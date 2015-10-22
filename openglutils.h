#define NULL 0
#define clrscr() system("clear")

extern unsigned long int ids;
extern int ii;
extern treenodo * genT;
extern treenodo * as;
extern int iii;
extern int nl;
extern int ik;
extern int ** nodel;
extern int * numbersINO;
extern int * numbersPRE;
extern int ** lsA;
int veces=0;

using namespace std;

/***************************************************OPENGL**********************************************/
void glucircle(GLfloat x, GLfloat y, GLfloat r)
{
    GLfloat PI=3.141592654, tPI=2.0f * PI;
    int lamt=100,i;
    glBegin(GL_LINE_LOOP);
    for(i=0;i<=lamt;i++)
    {
	glVertex2f(
	    x+(r*cos(i*tPI/lamt)),
	    y+(r*sin(i*tPI/lamt))
	);
    }
    glEnd();

}

void cpr( int elem)
{
    int i;
    char * bff=(char *)(malloc(10*sizeof(char)));
    sprintf(bff,"%d",elem);
    if(elem>0)
    {
    	for(i=0;i<strlen(bff);i++)
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,bff[i]);
    }
}

int bpl(int elem)
{
    int i;
    for(i=0;i<iii;i++)
    {
	if(nodel[0][i]==elem)
	    return nodel[1][i];
    }
}

int bpp(int elem, GLfloat ** aPOS)
{
    int i;
    for(i=0;i<iii;i++)
    {
	if(aPOS[0][i]==elem)
	    return i;
    }
}

GLfloat randG()
{
    return (rand()%10+1)/10.0f;
}

void impg_elem(GLfloat ** arraysPOS)
{
    int len=10,i,j, elem,bnn;
    GLfloat x=-0.7,y=.85; //-0.7 is for more space
    for(i=0;i<iii;i++) //Imp_elem Save Position
    {
	y=1.15;
	elem=numbersINO[i];
	x+=.12;
	y-=bpl(elem)*0.3;
	arraysPOS[0][i]=elem;
	arraysPOS[1][i]=x;
	arraysPOS[2][i]=y;
    	glRasterPos3f(x,y,0);
	cpr(elem);
    }

}

void NG_circles(GLfloat ** arraysPOS)
{
    int len=10,i,j, elem,bnn;
    GLfloat rad=.08;
    for(i=0;i<iii;i++) //N_Circles
    {
        glColor3f(randG(),randG(),randG());
	if(arraysPOS[0][i]<10)
  	    glucircle(arraysPOS[1][i]+.02,arraysPOS[2][i]+(rad/2)-.01,rad);
	else if (arraysPOS[0][i]>=10 && arraysPOS[0][i]<100)
	    glucircle(arraysPOS[1][i]+.02*2,arraysPOS[2][i]+(rad/2)-.01,rad);
	else
	    glucircle(arraysPOS[1][i]+.03*2,arraysPOS[2][i]+(rad/2)-.01,rad);
    }


}

void LineasG(GLfloat ** arraysPOS)
{
    int len=10,i,j, elem,bnn;
    glColor3f(1.0f,1.0f,1.0f);
    glLineWidth(1.0);
    for(i=0;i<iii;i++)  
    {
	if(lsA[1][i]!=-1) //Izq_Lines
	{
	    glBegin(GL_LINES);
	    glVertex2f(arraysPOS[1][bpp(lsA[0][i],arraysPOS)]+.02,arraysPOS[2][bpp(lsA[0][i],arraysPOS)]-.05);
	    glVertex2f(arraysPOS[1][bpp(lsA[1][i],arraysPOS)],arraysPOS[2][bpp(lsA[1][i],arraysPOS)]+.10);
	    glEnd();
	}
	if(lsA[2][i]!=-1) //Der_Lines
	{
	    glBegin(GL_LINES);
	    glVertex2f(arraysPOS[1][bpp(lsA[0][i],arraysPOS)]+.02,arraysPOS[2][bpp(lsA[0][i],arraysPOS)]-.05);
	    glVertex2f(arraysPOS[1][bpp(lsA[2][i],arraysPOS)],arraysPOS[2][bpp(lsA[2][i],arraysPOS)]+.10);
	    glEnd();
	}
    }

}

void glutGR()
{
    GLfloat ** arraysPOS,x=-0.4,y=.85;
    int len=10,i,j, elem,bnn;
    arraysutils au;
    arraysPOS=au.init_array(arraysPOS,3,iii);
    impg_elem(arraysPOS);
    NG_circles(arraysPOS);
    LineasG(arraysPOS);

}

void dspMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutGR();
    glFlush();
}

void opgl_init(int argc, char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(400,100); 
    glutCreateWindow("Arbol ABB");
    glEnable(GL_BLEND);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);
    glutDisplayFunc(dspMe);
    glutMainLoop();
}

/************************************************OPENGL*****************************************/

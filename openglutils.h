#include <GL/freeglut.h>
#define NULL 0
#define clrscr() system("clear")

extern unsigned long int ids;
extern int ii;
extern int iii;
extern int ** arbol;
extern int * numbersINO;
extern int * numbersPRE;

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


int nnsub(int * arr)
{
    int nsub=0, i=0;
    while (arr[i]!=-1)
    {
	i++;
    	nsub++;
    }
    return nsub;
}

int ipi(int elem,int * sub)
{
    int i;
    for(i=0;i<nnsub(sub);i++)
    {
	if(sub[i]==elem)
	{
	     //cout<<"SUBC: "<<sub[i]<<"-->"<<i<<endl;
	     return i;
	}
    }
}

int * sub_i(int idroot, int * arr)
{
    int * aux = (int *)(malloc(500*sizeof(int)));
    int i;
    for(i=0;i<idroot;i++)
    	aux[i]=arr[i];
    aux[i]=-1;
    return aux;
}

int * sub_d(int idroot, int * arr)
{
    int * aux = (int *)(malloc(500*sizeof(int)));
    int i,j=0;
    arraysutils au;
    for(i=idroot+1;i<nnsub(arr);i++)
    {
	aux[j]=arr[i];
	j++;
    }
    aux[j]=-1;
    /*cout<<"ARR2: ";
    cout<<"AUXNS: "<<nnsub(aux);
    cout<<endl;
    au.imp_vect(aux,nnsub(aux));*/
    return aux;
}

void imp_tree(GLfloat xi, GLfloat yi, int root, int * sub_R, int index)
{
    int i,ippi;
    GLfloat xid,xii,yid,yii;
    glRasterPos3f(xi, yi,0);
    int * izq_sub;
    int * der_sub;
    arraysutils au;
    if(index < iii)
    {
	cpr(root);
	ippi=ipi(root,sub_R);//General case
	//cout<<endl<<"ROOT: "<<root<<endl;
	izq_sub=sub_i(ippi,sub_R);
	der_sub=sub_d(ippi,sub_R);
	xii=xi-0.1;
	yii=yi-0.1;
	cout<<endl<<"ROOT: "<<root<<"->";
	cout<<ippi<<endl;
	//au.imp_vect(izq_sub,nnsub(izq_sub));
	index++;
	imp_tree(xii,yii,izq_sub[ipi(numbersPRE[index],izq_sub)],izq_sub,index);
	xid=xi+0.1;
	yid=yi-0.1;
	imp_tree(xid,yid,der_sub[ipi(numbersPRE[index],der_sub)],sub_d(ippi,sub_R),index);
    }
}

void glutext()
{
    GLfloat ** arraysPOS,x=0,y=.85;
    int Pivot;
    int len=iii,i,j;
    int * sub_R=(int *)(malloc(500*sizeof(int)));
    for (i=0;i<len;i++)
	sub_R[i]=numbersINO[i];
    sub_R[i]=-1;
    arraysutils au;
    glRasterPos3f(x, y,0);
    au.imp_vect(sub_R,len);
    /*arraysPOS=(GLfloat **)(malloc(len*sizeof(GLfloat)));
    for(i=0;i<3;i++)
	arraysPOS[i]=(GLfloat*)((malloc(3*sizeof(GLfloat))));*/
    imp_tree(x,y,numbersPRE[0],sub_R,0);
}

void dspMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    int i;
    GLfloat x=0.05, y=0.55 ,z=0.0, r=0.1,m=0,h=0;
    char *  buffer=(char *)malloc(50*sizeof(char));
    glutext();
    glFlush();
}

void opgl_init(int argc, char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(400,100); 
    glutCreateWindow("Hello Trees!!");
    glEnable(GL_BLEND);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);
    glutDisplayFunc(dspMe);
    glutMainLoop();
}

/************************************************OPENGL*****************************************/

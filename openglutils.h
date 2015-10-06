#include <GL/freeglut.h>
#define NULL 0
#define clrscr() system("clear")

extern unsigned long int ids;
extern int ii;
extern int ** arbol;
extern int * numbersINO;

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

void glutext()
{
    //text=(char *)malloc(50*sizeof(char));
    GLfloat ** arraysPOS,x=0,y=.85;
    int Pivot;
    int leen,i,j;
    glRasterPos3f(x, y,0);
    leen=1;
    arraysPOS=(GLfloat **)(malloc(leen*sizeof(GLfloat)));
    for(i=0;i<3;i++)
	arraysPOS[i]=(GLfloat*)((malloc(3*sizeof(GLfloat))));
    for(i=0;i<leen;i++)
    {
	if (i==0)
	{
    	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'A');
	    y-=0.1;
    	    glRasterPos3f(x-0.5, y,0);
	}
	else
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'A');
    }
}

void dspMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    int i;
    //glTranslatef(0.0f, 0.0f, 0.9f);
    GLfloat x=0.05, y=0.55 ,z=0.0, r=0.1,m=0,h=0;
    char *  buffer=(char *)malloc(50*sizeof(char));
    glutext();
    /*for(i=1;i<10;i++)
    {
    	glucircle(0,0,r+m);
    	glColor3f(0.0+h+m*3,0.1+h*2*h*m,0.2+h*m*m*m);
	m+=0.1;
	h+=0.2;
    }*/
    //glucircle(x+.5,y-.1,r);
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

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


void glutext()
{
    GLfloat ** arraysPOS,x=0,y=.85;
    int Pivot;
    int len=iii,i,j;
    arraysutils au;
    glRasterPos3f(x, y,0);
    au.imp_vect(numbersINO,5);
    /*arraysPOS=(GLfloat **)(malloc(len*sizeof(GLfloat)));
    for(i=0;i<3;i++)
	arraysPOS[i]=(GLfloat*)((malloc(3*sizeof(GLfloat))));*/
    cout<<"LEN: "<< len<<endl;
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

#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/freeglut.h>
//#include <conio.h>
#define NULL 0
#define sst "H:\\BGI"
#define clrscr() system("clear")
//#define getch() system("read a")

using namespace std;

GLfloat xx, yy;
char * numbersPRE;
char * numbersINO;
int ii=0;

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

void glutext(GLfloat x, GLfloat y,char * text)
{
     //text=(char *)malloc(50*sizeof(char));
     //GLfloat ** arraysPOS=(GLfloat *)(malloc(sizeof(GLfloat *)));
     glRasterPos3f(x, y,0);
     int len =(int) strlen(text),i;
     for(i=0;i<len;i++)
     	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
}

void dspMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glTranslatef(0.0f, 0.0f, 0.6f);
    GLfloat x=0.05, y=0.55 ,z=0.0, r=0.1;
    int leen;
    char *  buffer=(char *)malloc(50*sizeof(char));
    leen=strlen(numbersPRE);
    printf("nPRE: %d\n",leen);
    sprintf(buffer,numbersPRE);
    glutext(0.0,0.8,buffer);
    sprintf(buffer,numbersINO);
    glutext(0.0,0.5,buffer);
    glColor3f(0.1,0.5,0.9);
    glucircle(0,0.9,r);
    glucircle(x+.5,y-.1,r);
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

struct treenodo
{
    struct treenodo * izqptr;
    int dato;
    struct treenodo * derptr;
};

int ffstdin()
{
   int gc;
   while((gc=fgetc(stdin)) != EOF && gc != '\n'){}
}
void crear(treenodo * nodo)
{
    char resp[1];
    int gc;
    //nodo->dato=(char *)(malloc(40*sizeof(
    clrscr();
    cout<<"Entre el dato: ";
    scanf("%d",&nodo->dato);
    //ii++;
    gc=ffstdin();
    cout<<"Hay nodos a la Izquierda de ("<<nodo->dato << ") entre S/N: ";
    scanf("%s",resp);
    gc=ffstdin();
    if(strcmp(resp,"S")==0)
    {
	nodo->izqptr=NULL;
	nodo->izqptr= new (treenodo);
	crear(nodo->izqptr);
    }
    else
	nodo->izqptr=NULL;
    cout<<"Hay nodos a la Derecha de ("<<nodo->dato << ") entre S/N: ";
    scanf("%s",resp);
    gc=ffstdin();
    if (strcmp(resp,"S")==0)
    {
	nodo->derptr=new (treenodo);
	crear(nodo->derptr);
    }
    else
	nodo->derptr=NULL;
}

void preorden (treenodo * nodo)
{
    char * buffer=(char *)malloc(80*sizeof(char));
    if(nodo != NULL)
    {
	printf("%d ",nodo->dato);
	sprintf(buffer,"%d",nodo->dato);
	strcat(numbersPRE,buffer);
	preorden(nodo->izqptr);
	preorden(nodo->derptr);
    }
}

void postorden(treenodo * nodo)
{
    if(nodo != NULL)
    {
	postorden(nodo->izqptr);
	postorden(nodo->derptr);
	printf("%d ",nodo->dato);
    }
}

void inorden(treenodo * nodo)
{
    char * buffer=(char *)malloc(80*sizeof(char));
    if(nodo != NULL)
    {
	inorden(nodo->izqptr);
	printf("%d ",nodo->dato);
    	sprintf(buffer,"%d",nodo->dato);
    	strcat(numbersINO,buffer);
	inorden(nodo->derptr);
    }
}

int main(int argc, char ** argv)
{
    /*int gd=DETECT, gm;
    initgraph(&gd,&gm,sst);*/
    numbersPRE=(char *)(malloc(100*sizeof(char)));
    numbersINO=(char *)(malloc(100*sizeof(char)));
    xx=0;
    yy=0;
    strcat(numbersPRE,"");
    strcat(numbersINO,"");
    treenodo * nodo;
    nodo= new treenodo;
    crear(nodo);
    cout<<"PREORDEN ";
    preorden(nodo);
    printf("\n");
    cout<<"INORDEN ";
    inorden(nodo);
    printf("\n");
    cout<<"POSTORDEN ";
    postorden(nodo);
    printf("\n");
    xx=0.5;
    yy=0.5;
    opgl_init(argc,argv);
    //getch();
    return 0;
}



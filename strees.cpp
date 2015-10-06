#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "openglutils.h"
#include "arraysutils.h"
#include "treeutils.h"
#define NULL 0
#define clrscr() system("clear")
//#define getch() system("read a")

using namespace std;

int * numbersINO;
int ** arbol;
int ii=0;
unsigned long int ids=10;


int main(int argc, char ** argv)
{
    int i;
    numbersINO=(int *)(malloc(100*sizeof(int)));
    arbol=(int **)(malloc(3*sizeof(int*)));
    for(i=0;i<3;i++)
	arbol[i]=(int *)(malloc(500*sizeof(int)));
    arraysutils au;
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
    opgl_init(argc,argv);
    //getch();
    return 0;
}



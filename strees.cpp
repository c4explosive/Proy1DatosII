#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arraysutils.h"
#include "treeutils.h"
#include "openglutils.h"
#define NULL 0
#define clrscr() system("clear")
//#define getch() system("read a")

using namespace std;

int * numbersINO;
int * numbersPRE;
int ** arbol;
int ii=0,inn=0,iii=0;


int main(int argc, char ** argv)
{
    int i;
    int nI[5]={2,5,6,8,10};
    int nP[5]={8,5,2,6,10};
    numbersINO=(int *)(malloc(100*sizeof(int)));
    numbersPRE=(int *)(malloc(100*sizeof(int)));
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
    cout<<"ELE: "<<iii<<endl;
    /*for(i=0;i<iii;i++)
    {
	numbersINO[i]=nI[i];
	numbersPRE[i]=nP[i];
    }*/
    au.imp_vect(numbersINO,iii);
    opgl_init(argc,argv);
    //getch();
    return 0;
}



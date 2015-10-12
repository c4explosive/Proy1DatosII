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
int ** lsA;
int ** nodel;
treenodo * genT,* as;
int ii=0,inn=0,iii=0,il=0,nl=0,ik=0;


int main(int argc, char ** argv)
{
    int i,k;
    for(k=0;k<3;k++)
    {
    ii=0,inn=0,iii=0,il=0,nl=0,ik=0;
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
    /*cout<<"TRANSVERSAL ";
    transversal(nodo);*/
    nodel=au.init_array(nodel,2,iii);
    nodel=au.array_clear(nodel,2,iii);
    cout<<"PROFUNDIDAD "<<endl;
    plo(nodo);
    printf("\n");
    lsA=au.init_array(lsA,3,iii);
    lsA=au.array_clear(lsA,3,iii);
    hojas(nodo);
    genT=nodo;
    rellenar(lsA);
    cout<<"lsA: "<<endl;
    au.imp_array(lsA,3,iii);
    opgl_init(argc,argv);
    }
    //getch();
    return 0;
}



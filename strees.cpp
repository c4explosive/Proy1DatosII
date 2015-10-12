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
    int i;
    int nI[10]={7,5,3,10,6,9,2,1,4,8};
    int nP[10]={1,2,3,5,7,6,10,9,4,8};
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
    cout<<"TRANSVERSAL ";
    transversal(nodo);
    nodel=au.init_array(nodel,2,iii);
    cout<<"PROFUNDIDAD "<<endl;
    plo(nodo);
    printf("\n");
    lsA=au.init_array(lsA,3,iii);
    hojas(nodo);
    genT=nodo;
    rellenar(lsA);
    //cout<<"ELE: "<<iii<<endl;
    /*for(i=0;i<iii;i++)
    {
	numbersINO[i]=nI[i];
	numbersPRE[i]=nP[i];
    }
    iii=10;*/
    //au.imp_vect(numbersINO,iii);
    opgl_init(argc,argv);
    //getch();
    return 0;
}



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

using namespace std;

int * numbersINO;
int * numbersPRE;
int ** lsA;
int ** nodel;
treenodo * genT,* as;
int ii=0,inn=0,iii=0,il=0,nl=0,ik=0;

void initz(treenodo * nodo)
{
    ii=0,inn=0,iii=0,il=0,nl=0,ik=0;
    numbersINO=(int *)(malloc(100*sizeof(int)));
    numbersPRE=(int *)(malloc(100*sizeof(int)));
    arraysutils au;
    preorden(nodo);
    cout<<"INORDEN ";
    inorden(nodo);
    printf("\n");
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
}

void inss(treenodo *& nodo)
{
    int elemento;
    ii=0,inn=0,iii=0,il=0,nl=0,ik=0;
    numbersINO=(int *)(malloc(100*sizeof(int)));
    numbersPRE=(int *)(malloc(100*sizeof(int)));
    cout<<"ROOT: "<<nodo<<endl;
    printf("Ingrese un valor entero: ");
    scanf("%d", &elemento);
    if(elemento == 0)
	elemento=1;
    insABB(nodo, abs(elemento) );
    cout<<"INORDEN: "<<endl;
    inorden(nodo);
}


int main(int argc, char ** argv)
{
    int i,k,cont=1,elem;
    char op='\0';
    treenodo * nodo;
    nodo= NULL;
    do
    {
	clrscr();
	inss(nodo);
	initz(nodo);
    	opgl_init(argc,argv);
	clrscr();
	cout<<endl<<"¿Continuar? S/n: ";
	cin>>op;
	switch(op)
	{
	    case 's': case 'S': cont=1; break;
	    default: cont=0;
	}
	
    }while(cont);
    cout<<"Eliminar: ";
    cin>>elem;
    deleteABB(nodo,elem);
    if(nodo !=NULL)
    {
    	initz(nodo);
    	opgl_init(argc,argv);
    	cout<<"DIRR: "<<nodo<<endl;
    	cout<<"DATA: "<<nodo->dato<<endl;
    	cout<<endl;
    }
    //getch();
    return 0;
}



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define NULL 0
#define clrscr() system("clear")
#define getch() system("read ")
#include <string.h>
#include <time.h>
#include <math.h>
#include "arraysutils.h"
#include "treeutils.h"
#include "openglutils.h"
#include "menu.h"

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
    //cout<<"INORDEN ";
    inorden(nodo);
    //printf("\n");
    nodel=au.init_array(nodel,2,iii);
    nodel=au.array_clear(nodel,2,iii);
    //cout<<"PROFUNDIDAD "<<endl;
    plo(nodo);
    //printf("\n");
    lsA=au.init_array(lsA,3,iii);
    lsA=au.array_clear(lsA,3,iii);
    hojas(nodo);
    genT=nodo;
    rellenar(lsA);
}

void inss(treenodo *& nodo)
{
    char op='\0';
    int i,k,cont=1,elem;
    /*do
    {*/
	clrscr();
	/////
   	int elemento;
    	ii=0,inn=0,iii=0,il=0,nl=0,ik=0;
    	numbersINO=(int *)(malloc(100*sizeof(int)));
    	numbersPRE=(int *)(malloc(100*sizeof(int)));
   	 //cout<<"ROOT: "<<nodo<<endl;
    	printf("Ingrese un valor entero: ");
    	scanf("%d", &elemento);
    	if(elemento == 0)
	    elemento=1;
    	insABB(nodo, abs(elemento) );
    	//cout<<"INORDEN: "<<endl;
    	inorden(nodo);
	/////

}

int existe(treenodo *& nodo, int elem)
{
    initz(nodo);
    return sta(elem);
}

void crearr(treenodo *& nodo)
{
    char opp='\0';
    if(nodo !=NULL)
    {
	cout<<"¿Desea sobrescribir el arbol anterior?: ";
	cin>>opp;
	if(opp == 'S' || opp == 's')
	{
	    nodo= NULL;
            cout<<"Inserte la raiz"<<endl;
            inss(nodo);
            cout<<"Nuevo arbol creado con exito."<<endl;   
	}
	else
	    return;
    }
    else
    {
    	nodo= NULL;
    	cout<<"Inserte la raiz"<<endl;
    	inss(nodo);
    	cout<<"Nuevo arbol creado con exito."<<endl;
    }
}

void impp(treenodo *& nodo,int argc, char **argv)
{
    if(nodo !=NULL)
    {
    	initz(nodo);
	cout<<"INORDEN: ";
        inordenmpp(nodo);
    	opgl_init(argc,argv);
    }
    else
	cout<<"El arbol esta vacio, no se puede imprimir.";

}

void elimm(treenodo *& nodo)
{
    int elem, cont=1,i;
    arraysutils au;
    if(nodo != NULL)
    {
        do
	{
	    clrscr();
	    cout<<"Eliminar: ";
	    cin>>elem;
	    if(existe(nodo,elem))
	    {
		deleteABB(nodo,elem);
		cont=0;
	    }
	    else
	    {
		cout<<"No se puede eliminar, el nodo no existe."<<endl;
		cout<<"Nodos disponibles: ";
		au.imp_array(lsA,1,iii);
		getch();
		cont=1;
	    }
	}while(cont);
    }
    else
	cout<<"No se puede eliminar, el árbol está vacío"<<endl;

}


int main(int argc, char ** argv)
{
    treenodo * nodo;
    srand(time(NULL));
    clrscr();
    menu(nodo,argc,argv);
        //getch();
    return 0;
}



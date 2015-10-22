#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "arraysutils.h"
#include "treeutils.h"

using namespace std;

int * numbersINO;
int * numbersPRE;
int ** lsA;
int ** nodel;
treenodo * genT,* as;
int ii=0,inn=0,iii=0,il=0,nl=0,ik=0;



void insertaNodo( treenodo *ptrArbol, int valor);


int main()
{
	int i; 
	int elemento;
	treenodo * ptrRaiz=new treenodo;
	printf("INGRESE UN VALOR ENTERO\n");
	for(i=0;i<5;i++)
	{
		scanf("%d", &elemento);
		insertaNodo(ptrRaiz, elemento );
	}
	
}

void insertaNodo( treenodo * ptrArbol, int valor )
{
	if ( ptrArbol == NULL )
	{
		if ( ptrArbol != NULL )
		{
			ptrArbol->dato = valor;
			ptrArbol->izqptr = NULL;
			ptrArbol->derptr = NULL;
		}
		else
		{
			printf( "no se inserto %d. No hay memoria disponible.\n", valor );		
		}
	}
	else
	{
		if ( valor <  ptrArbol->dato )
		{
			insertaNodo(ptrArbol->izqptr, valor );
		}
		else if( valor > ptrArbol->dato )
		{
			insertaNodo( ptrArbol->derptr, valor );
		}
		else
		{
			printf( "dup" );
		}
	}
		
}


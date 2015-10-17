#include <stdio.h>
#include <stdlib.h>

struct nodoArbol
{
	struct nodoArbol *ptrIzq;
	int dato;
	struct nodoArbol *ptrDer;	
};

typedef struct nodoArbol NodoArbol;
typedef NodoArbol *ptrNodoArbol;


void insertaNodo( ptrNodoArbol *ptrArbol, int valor);
void inOrden( ptrNodoArbol ptrArbol );

int main()
{
	int i; 
	int elemento;
	ptrNodoArbol ptrRaiz=(ptrNodoArbol )malloc(sizeof(ptrNodoArbol));
	ptrRaiz = NULL;	
	printf("INGRESE UN VALOR ENTERO\n");
	for(i=0;i<5;i++)
	{
		scanf("%d", &elemento);
		insertaNodo( &ptrRaiz, elemento );
	}
	
}

void insertaNodo( ptrNodoArbol *ptrArbol, int valor )
{
	if ( *ptrArbol == NULL )
	{
		if ( *ptrArbol != NULL )
		{
			( *ptrArbol )->dato = valor;
			( *ptrArbol )->ptrIzq = NULL;
			( *ptrArbol )->ptrDer = NULL;
		}
		else
		{
			printf( "no se inserto %d. No hay memoria disponible.\n", valor );		
		}
	}
	else
	{
		if ( valor < ( *ptrArbol )->dato )
		{
			insertaNodo( &( ( *ptrArbol )->ptrIzq ), valor );
		}
		else if( valor > ( *ptrArbol )->dato )
		{
			insertaNodo( &( ( *ptrArbol )->ptrDer ), valor );
		}
		else
		{
			printf( "dup" );
		}
	}
		
}

void inOrden( ptrNodoArbol ptrArbol )
{
	if ( ptrArbol != NULL )
	{
		inOrden( ptrArbol->ptrIzq );
		printf( "%3d", ptrArbol->dato );
		inOrden( ptrArbol->ptrDer );
	}
	
}

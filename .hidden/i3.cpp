#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<stdlib.h>



struct nuevo
 	{
 		struct nuevo *subde;
 		struct nuevo *subiz;
 		int dato;		
	};
	
typedef struct nuevo elemento;
typedef elemento *arb;

void agregar(arb *arbol, int e);
int inorden (arb *arbol);
int postorden(arb *arbol);


void agregar(arb *arbol, int e)
{
	if(*arbol==NULL)	
	{
		//*arbol = malloc(sizeof(elemento));
		
		if( *arbol!=NULL)
		{
			(*arbol) -> dato=e;
			(*arbol)->subiz=NULL;
			(*arbol)->subde=NULL;
		}
	}
	else
	{
		if(e<(*arbol)->dato)
		agregar(&((*arbol)->subiz), e);
		else if (e>(*arbol)->dato)
		agregar(&((*arbol)->subde), e);
		else
		printf("EL VALOR YA EXISTE");
	}
}

int inorden (arb *arbol)
{
 if (*arbol!=NULL)
 {
   inorden(&(*arbol)->subiz);
   printf("%d  ", (*arbol)->dato);
   inorden(&(*arbol)->subde);
 }return 0;
}

postorden(arb *arbol)
{
    if ((*arbol)!=NULL)
 {
  postorden (&(*arbol)->subiz);
  postorden (&(*arbol)->subde);
  printf("%d ", (*arbol)->dato);
 }return 0;
}

int main()
{
 int num, i;
 arb raiz = NULL;
 	
 	
	printf("INGRESE UN VALOR ENTERO");
	
	for(i=0;i<5;i++)
	{
	scanf("%d", &num);
	agregar((*raiz), num);
	}
	printf("\nPOSTORDEN\n");
	postorden(*raiz);
	printf("\nINORDEN\n");
	inorden(*raiz);
	
return 0;
}

#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<windows.h>


#define NULO 0



struct nuevo
 	{
 		struct nuevo *subde;
 		struct nuevo *subiz;
 		int dato;
 		
	};

void agregar(nuevo *elemento, int num)
{
	nuevo *subde= new (nuevo);
	nuevo *subiz= new (nuevo);
	
	while(num!=NULO)
	{
		if(elemento->dato==NULO)
		{
			elemento->dato=num;
			elemento->subde=NULO;
			elemento->subiz=NULO;
		}
		else if(num>elemento->dato)
		{	
			//nuevo *subde= new nuevo;
			agregar(subde, num);	
		}
		else
		{
			//nuevo *subiz= new nuevo;
			agregar(subiz, num);	
		}
	}		
}

int inorden (nuevo *a)
{
 if (a!=NULL)
 {
   inorden(a->subiz);
   printf("%d  ", a->dato);
   inorden(a->subde);
 }return 0;
}

int main()
{
	nuevo *arbol;
	arbol=new nuevo;
	arbol=NULO;
	int n=1;
	void agregar(nuevo *elemento, int num);
	int inorden (nuevo *a);
	
	while(n!=NULO)
	{
		printf("INTRODUZCA UN VALOR ENTERO: \n");
		scanf("%d", &n);
		agregar(arbol, n);
	}
	
	inorden(arbol);
	
}

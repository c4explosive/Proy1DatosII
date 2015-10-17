#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<windows.h>


struct _nuevo
 	{
 		struct _nuevo *subde;
 		struct _nuevo *subiz;
 		int dato;
 		
	}ta;
	
struct ta *elemento;
struct ta *arb;

void agregar(struct ta *nuevo, int num)
{
	elemento padre = NULL;
   	elemento actual = *nuevo;
   	
   	while(actual!=NULL && num != actual->dato) 
	{
      padre = actual;
      if(num > actual->dato) 
	  actual = actual->subde;
      else if(num < actual->dato) 
	  actual = actual->subiz;
   	}
   	 if(actual==NULL) return;
   	 
   	 if(padre==NULL) 
		actual = new elemento(num);
   	 
   	 else if(dat < padre->dato) 
		padre->subiz = new elemento(num);
   	 
   	 else if(dat > padre->dato) 
		padre->subdiz = new elemento(num);
}

int inorden (ta *arbol)
{
 if (arbol!=NULL)
 {
   inorden(arbol->subiz);
   printf("%d  ", arbol->dato);
   inorden(arbol->subde);
 }return 0;
}

int main()
{
	
	
	arb=NULL;
	int n=1;
	void agregar(ta *nuevo, int num);
	int inorden (ta *b);
	
	while(n!=NULO)
	{
		printf("INTRODUZCA UN VALOR ENTERO: \n");
		scanf("%d", &n);
		agregar(arb, n);
	}
	
	inorden(arbol);
	
}

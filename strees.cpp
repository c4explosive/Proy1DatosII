#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <conio.h>
#define NULL 0
#define clrscr() system("clear")
#define getch() system("read a")

using namespace std;

struct treenodo
{
    struct treenodo * izqptr;
    int dato;
    struct treenodo * derptr;
};

int ffstdin()
{
   int gc;
   while((gc=fgetc(stdin)) != EOF && gc != '\n'){}
}
void crear(treenodo * nodo)
{
    char resp[1];
    int gc;
    //nodo->dato=(char *)(malloc(40*sizeof(
    clrscr();
    cout<<"Entre el dato: ";
    scanf("%d",&nodo->dato);
    gc=ffstdin();
    cout<<"Hay nodos a la Izquierda de ("<<nodo->dato << ") entre S/N: ";
    scanf("%s",resp);
    gc=ffstdin();
    if(strcmp(resp,"S")==0)
    {
	nodo->izqptr=NULL;
	nodo->izqptr= new (treenodo);
	crear(nodo->izqptr);
    }
    else
	nodo->izqptr=NULL;
    cout<<"Hay nodos a la Derecha de ("<<nodo->dato << ") entre S/N: ";
    scanf("%s",resp);
    gc=ffstdin();
    if (strcmp(resp,"S")==0)
    {
	nodo->derptr=new (treenodo);
	crear(nodo->derptr);
    }
    else
	nodo->derptr=NULL;
}

void preorden (treenodo * nodo)
{
    if(nodo != NULL)
    {
	printf("%d ",nodo->dato);
	preorden(nodo->izqptr);
	preorden(nodo->derptr);
    }
}

void postorden(treenodo * nodo)
{
    if(nodo != NULL)
    {
	postorden(nodo->izqptr);
	postorden(nodo->derptr);
	printf("%d ",nodo->dato);
    }
}

void inorden(treenodo * nodo)
{
    if(nodo != NULL)
    {
	inorden(nodo->izqptr);
	printf("%d ",nodo->dato);
	inorden(nodo->derptr);
    }
}

int main()
{
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
    getch();
    return 0;
}



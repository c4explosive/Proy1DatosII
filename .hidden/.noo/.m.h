﻿/* Integrantes:
   	Angel Espinosa
   	Eduardo Perez
   Grupo:
   	1IL121
*/
#include <stdio.h>
#include <stdlib.h>
#define getch() system("read ") //Comentar estas dos lineas "defines".
#define clrscr() system("clear")

struct treenodo
{
    struct treenodo * izqptr;
    int dato;
    struct treenodo * derptr;
};


typedef struct col
{
    treenodo *cola; //Array donde se insertan los elementos
    int capacity; //Capacidad de la cola
    int tam; // tamaño actual de la cola
    treenodo* frente; //Puntero o dirección de memoria del frente
    treenodo* final; // Puntero o dirección de memoria del final
    int nfr,nfi; //Enteros que almacenan el índice de posoción final e inicial.
}cl;

//Vacía
int vac(cl * Q)
{
    if (Q->tam != 0)
	return 0;
    else
	return 1;
}

//Llena

int lle(cl * Q)
{
    if (Q->tam >= Q->capacity)
	return 1;
    else
	return 0;
}

//Create
cl * create(int maxE)
{
   cl *Q=malloc(sizeof(cl)); //Poner MaxE*sizeof... por si acaso
   Q->cola=(treendo *)malloc(maxE*sizeof(treenodo));
   Q->tam=0;
   Q->capacity=maxE;
   Q->frente=&(Q->cola[0]);
   Q->final=&(Q->cola[0]);
   Q->nfr=1;
   Q->nfi=1;
   return Q;
}

//delete elements

void elim(cl * Q, treenodo elem)
{
    int s,pl=0;
    int * pt;
    if  (Q->tam==0)
	printf("La cola está vacía\n");
    else
    {
	if (pl)
	{
	    do
	    {
    	    	s=(int)*Q->frente;
    	    	Q->frente++;
		Q->nfr++;
	    	Q->tam--;
	    } while ( s != elem);
	}
	else
	    printf("No existe el elemento.\n");
    }
}

//Insert elements
void ins(cl * Q, treenodo elem)
{
    if (lle(Q))
	printf("Cola llena no se puede ingresar mas elementos\n");
    else
    {
    	*Q->final=elem;
    	Q->final++;
	Q->nfi++;
    	Q->tam++;
    }
}

/*//Display elements of queue
void display(cl *qu)
{
    int * pt;
    if (!vac(qu))
    {
    	pt=qu->frente;
    	printf("Cola: ");
    	while ( pt != qu->final)
    	{
	    printf("%c, ",*pt);
   	    pt++;
    	}
    	printf("\b\b \n");
    }
    else
	printf("La cola está vacía.\n");
    if (lle(qu))
	printf("La cola está llena.\n");
}*/


void frfi(cl * Q)
{
    printf("El frente es: %d y el final: %d\n",Q->nfr,Q->nfi);
}
/*
/////////////////////////////////////////////////////////////////////////////////
void menu()
{
    int op, sp=0;
    char cont=1;char elem;
    cl * cl1;
    char * opp=malloc(sizeof(char));
    do
    {
	clrscr();
	printf("Operaciones con colas\n");
	printf("1. Ingresar el tamaño de la cola.\n");
	printf("2. Insertar.\n");
	printf("3. Eliminar.\n");
	printf("4. Ver Cola.\n");
	printf("5. Salir.\n");
	printf("Escriba la opciòn: ");
	scanf("%s",opp);
	fflush(stdin);
	op=atoi(opp);
	switch(op)
	{
	    case 1:
		if (sp)
		    printf("El tamaño de cola, ya está definido.\n");
		else
		{
		    printf("Ingrese el tamaño de la cola: ");
		    scanf("%s",opp);
		    fflush(stdin);
    		    cl1 = create(atoi(opp));
		    sp=1;
		}
		getch();
		break;
	    case 2:
		if (sp)
		{
		    printf("Escriba el elemento a ingresar: ");
		    scanf("%s",opp);
		    fflush(stdin);
		    elem=opp[0];
		    ins(cl1,elem);
		    display(cl1);
		}
		else
		    printf("Ingrese el tamaño de la cola primero.\n");
		getch();
		break;
	    case 3:
		if (sp)
		{
		    printf("Escriba el elemento hasta donde eliminar: ");
		    scanf("%s",opp);
		    fflush(stdin);
		    elem=opp[0];
		    elim(cl1,elem);
		    display(cl1);
		}
		else
		    printf("Ingrese el tamaño de la cola primero.\n");
		getch();
		break;
	    case 4:
		if(sp)
		{
	            display(cl1);
		}
		else
		    printf("Ingrese el tamaño de la cola primero.\n");
		getch();
		break;
	    case 5:
		cont=0;

		default:
            printf("Opción Invalida, Intente de nuevo\n");
	}
    }while (cont);
}
void main()
{
    menu();
}
*/

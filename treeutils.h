#include "queue.h"
#define NULL 0
#define clrscr() system("clear")

extern int ii;
extern int inn;
extern int iii;
extern int il;
extern int ** nodel;
extern int * numbersINO;
extern int * numbersPRE;

using namespace std;

/**********************************************TREES*******************************************/
/*struct treenodo
{
    struct treenodo * izqptr;
    int dato;
    struct treenodo * derptr;
};*/


int ffstdin()
{
   int gc;
   while((gc=fgetc(stdin)) != EOF && gc != '\n'){}
}
void crear(treenodo * nodo)
{
    char resp[1];
    int gc;
    arraysutils au;
    clrscr();
    cout<<"Entre el dato: ";
    scanf("%d",&nodo->dato);
    gc=ffstdin();
    cout<<"Hay nodos a la Izquierda de ("<<nodo->dato << ") entre S/N: ";
    scanf("%s",resp);
    gc=ffstdin();
    if(strcmp(resp,"S")==0)
    { 
	nodo->izqptr= new (treenodo);
	crear(nodo->izqptr);
    }
    else
    {
	nodo->izqptr=NULL;
    }
    cout<<"Hay nodos a la Derecha de ("<<nodo->dato << ") entre S/N: ";
    scanf("%s",resp);
    gc=ffstdin();
    if (strcmp(resp,"S")==0)
    {
	nodo->derptr=new (treenodo);
	crear(nodo->derptr);
    }
    else
    {
	nodo->derptr=NULL;
    }
}

void preorden (treenodo * nodo)
{
    char * buffer=(char *)malloc(80*sizeof(char));
    if(nodo != NULL)
    {
	printf("%d ",nodo->dato);
	numbersPRE[ii]=nodo->dato;
	ii++;
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
    char * buffer=(char *)malloc(80*sizeof(char));
    if(nodo != NULL)
    {
	inorden(nodo->izqptr);
	printf("%d ",nodo->dato);
	numbersINO[inn]=nodo->dato;
	inn++;
	iii++;
	inorden(nodo->derptr);
    }
}

void transversal(treenodo *tr)
{
    queue *cola;
    treenodo * aux;
    int i=0;
    int nICL=1;
    int nINL=0;
    if(tr!=NULL)
    {
	create(&cola);
	encolar(&cola,tr);
	while(i<iii)
	{
	    desencolar(&cola,&aux);
  	    cout<<aux->dato<<" ";
	    if(aux->izqptr != NULL)
		encolar(&cola,aux->izqptr);
	    if(aux->derptr != NULL)
		encolar(&cola,aux->derptr);
	    i++;
	}
    }
    cout<<endl;
}

int maxH(treenodo * p)
{
    if(!p) return 0;
    int lefth=maxH(p->izqptr);
    int righth=maxH(p->derptr);
    return (lefth > righth) ? lefth + 1 : righth +1;
}

void plevel(treenodo * p, int level,int levnm)
{
    if(!p) return;
    if(level ==1)
    {
	cout<<p->dato<<" ";
	nodel[0][il]=p->dato;
	nodel[1][il]=levnm;
	il++;
    }
    else
    {
	plevel(p->izqptr, level-1,levnm);
	plevel(p->derptr, level-1,levnm);
    }
}

void plo(treenodo * root) //Le saca los nodos dependiendo del nivel
{
    int height=maxH(root);
    int level=1;
    for(level =1; level <=height; level++)
    {
	plevel(root,level,level);
	cout<<"LEVEL: "<<level;
	cout<<endl;
    }   
}
/******************************************TREEs***********************************************/

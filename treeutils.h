#define NULL 0
#define clrscr() system("clear")

struct treenodo
{
    struct treenodo * izqptr;
    int dato;
    struct treenodo * derptr;
};

extern int ii;
extern int inn;
extern int iii;
extern int il;
extern int nl;
extern int ** nodel;
extern int * numbersINO;
extern int * numbersPRE;
extern int ** lsA;
extern int ik;
extern treenodo * genT;
extern treenodo * as;

using namespace std;

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

void insABB( treenodo *& nodo, int elem )
{
    if ( nodo == NULL )
    {
	nodo=new treenodo;
	cout<<"DIRT: "<<nodo<<endl;
	if ( nodo != NULL )
	{
	    //cout<<"DATO: "<<ptrArbol->dato<<endl;
	    cout<<"DIRT: "<<nodo<<endl;
	    nodo->dato = elem;
	    nodo->izqptr = NULL;
	    nodo->derptr = NULL;
	}
	else
	{
	    printf( "no se inserto %d. No hay memoria disponible.\n", elem );		
	}
    }
    else
    {
	if ( elem <  nodo->dato )
	{
	    insABB(nodo->izqptr, elem );
	}
	else if( elem > nodo->dato )
	{
	    insABB( nodo->derptr, elem );
	}
	else
	{
	    printf( "Duplicado" );
	}
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


void hojas (treenodo *nodo)
{
    if(nodo->izqptr == NULL && nodo->derptr == NULL)
    {
	lsA[0][nl]=nodo->dato;
	lsA[1][nl]=-1;
	lsA[2][nl]=-1;
	nl++;
    }
    else
    {
	if(nodo->izqptr != NULL)
	{
	    hojas(nodo->izqptr);
	}
	else
	{
	    lsA[0][nl]=nodo->dato;
            lsA[1][nl]=-1;
	    nl++;
	}
	if(nodo->derptr != NULL)
	{
	    hojas(nodo->derptr);
	}
	else
	{
	    lsA[0][nl]=nodo->dato;
            lsA[2][nl]=-1;
            nl++;
	}
    }
}

int dcero(int index)
{
    int i;
    for(i=0;i<iii;i++)
    {
	if(lsA[index][i]==0)
	    return i;
    }
    return -2;
}

int sta(int elem)
{
    int i;
    for(i=0;i<iii;i++)
    {
	if(lsA[0][i]==elem)
	    return 1;
    }
    return 0;
}

void preorden_extract (treenodo * nodo, int elem)
{
    if(nodo != NULL)
    {
	if(nodo->dato == elem)
	{
	   as=nodo;
	}
	preorden_extract(nodo->izqptr,elem);
	preorden_extract(nodo->derptr,elem);
	
    }
    
}


void rellenar(int ** lsA)
{
    int i,ps;
    treenodo * asunder;
    for(i=0;i<iii;i++)
    {
	ps=dcero(0);	
	if(sta(numbersPRE[i])==0)
	    lsA[0][ps]=numbersPRE[i];
    } //Nodos que faltaban
    ps=1;
    do
    {
	ps=dcero(1);
	cout<<"PS: "<<ps<<endl;
	if(ps!=-2)
	{
	    preorden_extract(genT, lsA[0][ps]);
	    asunder=as;
	    lsA[1][ps]=asunder->izqptr->dato;
	}
    }while(ps!=-2);//Punteros izquierdos faltantes
    ps=1;
    do
    {
	ps=dcero(2);
	cout<<"PS: "<<ps<<endl;
	if(ps!=-2)
	{
	    preorden_extract(genT, lsA[0][ps]);
	    asunder=as;
	    lsA[2][ps]=asunder->derptr->dato;
	}
    }while(ps!=-2);//Punteros derechos faltantes

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

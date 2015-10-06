#define NULL 0
#define clrscr() system("clear")

extern unsigned long int ids;
extern int ii;
extern int ** arbol;
extern int * numbersINO;

using namespace std;

/**********************************************TREES*******************************************/
struct treenodo
{
    struct treenodo * izqptr;
    int id;
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
    clrscr();
    cout<<"IDs: "<<ids<<endl;
    cout<<"Entre el dato: ";
    ids++;
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
    char * buffer=(char *)malloc(80*sizeof(char));
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
    char * buffer=(char *)malloc(80*sizeof(char));
    if(nodo != NULL)
    {
	inorden(nodo->izqptr);
	printf("%d ",nodo->dato);
	inorden(nodo->derptr);
    }
}

/******************************************TREEs***********************************************/

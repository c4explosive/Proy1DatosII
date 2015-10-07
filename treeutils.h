#define NULL 0
#define clrscr() system("clear")

extern unsigned long int ids;
extern int ii;
extern int iii;
extern int ** arbol;
extern int * numbersINO;
int ing=1,ni=1,pa=1;

using namespace std;

/**********************************************TREES*******************************************/
struct treenodo
{
    struct treenodo * izqptr;
    int id;
    struct treenodo * dadnodo;
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
    arraysutils au;
    clrscr();
    //cout<<"IDs: "<<ids<<endl;
    cout<<"Entre el dato: ";
    scanf("%d",&nodo->dato);
    gc=ffstdin();
    //au.imp_array(arbol,3,ii);
    if(ing==1)
    {
    	nodo->id=ids;
    	arbol[0][ii]=nodo->id;
    	arbol[1][ii]=nodo->dato;
    	arbol[2][ii]=ni;
 	ii++;
	ing++;
	ids++;
    	ni++;
    }
    cout<<"Hay nodos a la Izquierda de ("<<nodo->dato << ") entre S/N: ";
    scanf("%s",resp);
    gc=ffstdin();
    if(strcmp(resp,"S")==0)
    { 
	ing=1;
	pa=1;
	nodo->izqptr= new (treenodo);
	crear(nodo->izqptr);
    }
    else
    {
	nodo->izqptr=NULL;
	if(pa==1)
	    ni--;
	pa=0;
	ing=0;
    }
    cout<<"Hay nodos a la Derecha de ("<<nodo->dato << ") entre S/N: ";
    scanf("%s",resp);
    gc=ffstdin();
    if (strcmp(resp,"S")==0)
    {
	ing=1;
	pa=1;
	nodo->derptr=new (treenodo);
	crear(nodo->derptr);
    }
    else
    {
	nodo->derptr=NULL;
	if(pa==1)
	    ni--;
	pa=0;
	ing=0;
    }
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
	iii++;
	inorden(nodo->derptr);
    }
}

/******************************************TREEs***********************************************/

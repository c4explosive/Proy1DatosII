struct treenodo
{
    struct treenodo * izqptr;
    int dato;
    struct treenodo * derptr;
};

struct queue
{
    treenodo * clave;
    struct queue * sig;
};

void create(struct queue ** cola)
{
    *cola=NULL;
}

int vacia (struct queue * cola)
{
    return (cola==NULL);
}

void encolar(struct queue ** cola, treenodo * elem)
{

    struct queue * nuevo;
    nuevo=(struct queue *)(malloc(sizeof(struct queue)));
    nuevo->clave=elem;
    if(*cola == NULL)
	nuevo->sig=nuevo;
    else
    {
	nuevo->sig=(*cola)->sig;
	(*cola)->sig=nuevo;
    }
    (*cola)=nuevo;
}

void desencolar(struct queue ** c1, treenodo ** elem)
{
     struct queue * aux;
if((*c1)->sig!=NULL)
{
     *elem=(*c1)->sig->clave;
     if ((*c1) ==  (*c1)->sig)
     {
	free(*c1);
	*c1=NULL;
     }
     else
     {
	aux = (*c1)->sig;
	(*c1)->sig=aux->sig;
	free(aux);
     }
}
}

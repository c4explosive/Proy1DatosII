void inss(treenodo *&);
void crearr(treenodo *&);
void elimm(treenodo *&);
void impp(treenodo *&, int argc, char **argv);
 void presentacion ()
{
 
 printf("\n\n\t\t        UNIVERSIDAD TECNOLOGICA DE PANAMA");
 printf("\n\t\tFACULTAD DE INGENIERIA EN SISTEMAS COMPUTACIONALES");
 printf("\n\t\t   LIC. DE INGENIERIA EN SISTEMAS Y COMPUTACION");
 printf("\n\n\t\t              ESTRUCTURA DE DATOS II");
 printf("\n\t\t                 PROYECTO No. 1");
 printf("\n\t\t            ARBOL BINARIO DE BUSQUEDA");
 printf("\n\n\t\tFACILITADORA:");
 printf("\n\n\t\t              ING. YOLANDA DE MIGUELENA");
 printf("\n\n\t\tINTEGRANTES:");
 printf("\n\n\t\t            ESPINOSA, ANGEL     8-905-1352");
 printf("\n\t\t            GONZALEZ, YORLENIS  9-749-2051");
 printf("\n\t\t            OJO,      KARINA    8-894-719");
 printf("\n\n\t\t                   GRUPO 1IL121\n");
 printf("\n\n\t\t               22 DE OCTUBRE DE 2015\n");
 
}

void menu(treenodo *& nodo, int argc, char ** argv)
{
     int opm=0;
     do
  {
  printf("\n\n\n\t\t\t     PROYECTO Nø1");
  printf("\n\t\t\tARBOL BINARIO DE BUSQUEDA");
  printf("\n\n\t\t1. PRESENTACION");
  printf("\n\t\t2. CREAR ARBOL ABB");
  printf("\n\t\t3. ADICIONAR NODOS AL ARBOL ABB");
  printf("\n\t\t4. ELIMINAR NODOS AL ARBOL ABB");
  printf("\n\t\t5. IMPRIMIR EL ARBOL ABB");
  printf("\n\t\t6. SALIR");

  printf("\n\n\tIntroduzca la opci¢n de su preferencia  ");
  cin>>opm;
  //scanf("%d", &opm);
  clrscr();
     switch(opm)
     {
      case 1 : presentacion();
               getch();
	           clrscr();
	       break;

      case 2 : 
               //AQUI VA LA CREACION DEL ARBOL
	       crearr(nodo);
               getch();
	       clrscr();
			 break;
      case 3 :
               //ADICION O INSERCION DE NODOS
               inss(nodo);
               //getch();
	           clrscr();
			 break;
      case 4 : 
               //ELIMINAR NODOS
               elimm(nodo);
               getch();
	           clrscr();
			 break;
      case 5 : 
               //IMPRIMIR ARBOL ABB
               impp(nodo,argc,argv);
               //getch();
	           clrscr();
			 break;

      case 6 : printf("\n\n\tQUE TENGA UN BUEN DIA\n");
               getch();
	           clrscr();
	       break;

      default: printf("\n\n\n\n\tLA OPCION INGRESADA NO ESTA CONTEMPLADA. INGRESE 1, 2 ¢ 3\r\n");
	   getch();
	   clrscr();
	   break;
     }
     
 }while(opm!=6);
     
}

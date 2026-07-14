#include <iostream>
#include <conio.h>
#include <stdlib.h>

struct nodo{
       int x;
       nodo *izq,*der;
       };
       
void enlazar(nodo *aux, nodo *n);
void mostrarinorden(nodo *aux);
void mostrarpreorden(nodo *aux);
void mostrarpostorden(nodo *aux);
nodo *raiz;

using namespace std;       
main()
    {
    nodo *aux,*p;
    raiz=NULL;
    int op, busqueda, cont;
    do
    	{
        cout<<"\n\n MENU\n\n1.Agregar nodo\n2.Arbol inorden\n3.Arbol preorden\n4.Arbol postorden\n5.Salir\n\n Digite su opcion....";
        cin>>op;
        switch(op)
        	{
            case 1:	
     				p=(nodo *) malloc (sizeof(struct nodo));
     				cout<<"Dato ";
     				cin>>p->x;
     				p->izq=p->der=NULL;
     				enlazar(raiz,p);
        			break;
        	case 2:	cout<<"\nEl arbol organizado en inorden es: "<<endl;
        			mostrarinorden(raiz);
        			getch();
      				break;
      		case 3:	cout<<"\nEl arbol organizado en preorden es: "<<endl;
			  		mostrarpreorden(raiz);
      				getch();
      				break;
      		case 4:	cout<<"\nEl arbol organizado en postorden es: "<<endl;
      				mostrarpostorden(raiz);
      				getch();
      				break;
      		case 5: cont=0;
      				cout<<"\nIngrese numero a buscar: ";
      				cin>>busqueda;
      				buscar(raiz);
      				getch();
      				break;
      				
      		default: cout<<"\nEl programa ha terminado"<<endl;
      				getch();  
      				break;
      		}
		}while (op!=6);
    }

void enlazar(nodo *aux, nodo *n)
     {
     if(aux==NULL)
                  raiz=n;
     else
         {
         if(n->x<aux->x)
                        if(aux->izq==NULL)
                                        aux->izq=n;
                        else
                            enlazar(aux->izq,n);
         else         
                      if(aux->der==NULL)
                                        aux->der=n;
                      else
                            enlazar(aux->der,n);
         }
     }

void mostrarinorden(nodo *aux)
     {
     if(aux==NULL)
                  return;
                    
     
     mostrarinorden(aux->izq);
     cout<<" "<<aux->x;
     mostrarinorden(aux->der);
     }
void mostrarpreorden(nodo *aux)
     {
	 if(aux==NULL)
	 		return;
	 cout<<" "<<aux->x;
	 mostrarpreorden(aux->izq);
	 mostrarpreorden(aux->der);
     return;
     }
void mostrarpostorden(nodo *aux)
     {
     if(aux==NULL)
     	return;
     mostrarpostorden(aux->izq);
     mostrarpostorden(aux->der);
     cout<<" "<<aux->x;
     return;
     }
void buscar(nodo *aux)
     {
     if(aux==NULL)
                  return;
     cont++;
     mostrarinorden(aux->izq);
     if(aux->x==busqueda)
     {
     	cout<<"Numero encontrado "<<endl;//"	Numero: "<<busqueda<<"	Nivel: "<<cont;
     	while
     	//if(busqueda>raiz->x)
     	//	cout<<"	"
	 }
     mostrarinorden(aux->der);
     }
  

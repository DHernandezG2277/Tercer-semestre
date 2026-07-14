#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo
{
	int n;
	Nodo *sig, *ant;	
};

int main()
{
	Nodo *cab, *ult, *p, *aux, *aux2;
	cab=ult=p=aux=NULL;
	int op, busqueda;
	string insertar;
	do
	{
		cout<<"\n\n1. Agregar al inicio\n2. Agregar al final\n3. Mostrar desde el inicio\n4. Mostrar desde el final\n5. Insertar\n7. Eliminar\n10. Salir\n Opcion: ";
		cin>>op;
		switch(op)
		{
			case 1:
				{
					p=(Nodo *)malloc(sizeof(struct Nodo));
					cout<<"Ingrese numero entero: ";
					cin>>p->n;
					
					if(cab==NULL)
					{
						p->sig=p->ant=NULL;
						cab=ult=p;
					}
					
					else
					{
						p->sig=cab;
						p->ant=NULL;
						cab->ant=p;
						cab=p;
					}
					break;
				}
			case 2:
				{
					p=(Nodo *)malloc(sizeof(struct Nodo));
					cout<<"Ingrese numero entero: ";
					cin>>p->n;
					
					if(ult==NULL)
					{
						p->sig=p->ant=NULL;
						cab=ult=p;
					}
					
					else
					{
						p->sig=NULL;
						p->ant=ult;
						ult->sig=p;
						ult=p;
					}
					break;
				}		
			case 3:
				{
					aux=cab;
					cout<<"La lista ingresada desde el inicio fue: "<<endl;
					while(aux!=NULL)
					{
						cout<<aux->n<<"	";
						aux=aux->sig;
					}
					break;
				}
			case 4:
				{
					aux=ult;
					cout<<"La lista ingresada desde el final fue: "<<endl;
					while(aux!=NULL)
					{
						cout<<aux->n<<"	";
						aux=aux->ant;
					}
					break;
				}
			case 5:
				{
					busqueda=0;
					cout<<"\nInsertar adelante o detras?: ";
					cin>>insertar;
					if(insertar == "adelante")//aqui para insertar delante de 
					{
						aux=cab;
						cout<<"Insertar adelante de :";
						cin>>busqueda;
						while(aux!=NULL)
						{
							if(aux->n==busqueda)
								break;
							aux=aux->sig;
						}
						
						if(aux==NULL)
						{
							cout<<"\nEl numero ingresado no se encuentra en la lista"<<endl;
							break;
						}
						else if(aux==ult)//si es el ultimo
						{
							cout<<"\nNo se puede insertar adelante del final de la cola. Regresando al menu..."<<endl;
							break;
						}
						
						else//si es un numero cualquiera o cabeza de la fila
						{
							p=(Nodo *)malloc(sizeof(struct Nodo));
							cout<<"Ingrese numero entero a insertar: ";
							cin>>p->n;
							
							aux2=aux->sig;
							p->sig=aux2;
							p->ant=aux;
							aux2->ant=p;
							aux->sig=p;
							break;
						}
					}
					else//esto es para insertras detras de
					{
						aux=cab;
						cout<<"Insertar detras de :";
						cin>>busqueda;
						while(aux!=NULL)
						{
							if(aux->n==busqueda)
								break;
							aux=aux->sig;
						}
						if(aux==NULL)//miramos si aux se paso
						{
							cout<<"\nEl numero ingresado no se encuentra en la lista"<<endl;
							break;
						}
						else if(aux==cab)//sino pues miramos si aux==cab
						{
							cout<<"\nNo se puede insertar detras del inicio de la cola. Regresando al menu..."<<endl;
							break;
						}
						else//o si es un numero mas de la lista
						{
							p=(Nodo *)malloc(sizeof(struct Nodo));
							cout<<"Ingrese numero entero a insertar: ";
							cin>>p->n;
							
							aux2=aux->ant;
							p->sig=aux;
							p->ant=aux2;
							aux->ant=p;
							aux2->sig=p;
							break;
						}
					}
					break;
				}
			case 7:
				{
					busqueda=0;
					cout<<"Que numero desea eliminar? :";
					cin>>busqueda;
					aux=cab;
					while(aux!=NULL)
					{
						if(aux->n==busqueda)
							break;
						aux=aux->sig;
					}
					if(aux==NULL)//Analizamos si llego aux al final 
					{
						cout<<"\nEl numero ingresado no se encuentra en la lista o la lista esta vacia"<<endl;
						break;
					}
					else if(aux==cab)//determinamos si aux==cab
					{
						cab=cab->sig;
						if(cab==NULL)//si solo habia un elemento
						{
							ult=NULL;
							cout<<"\nNodo eliminado: "<<aux->n<<endl;
							free(aux);
						}
						else//si habia mas de un elemento
						{
							cab->ant=NULL;
							aux->sig=NULL;
							cout<<"\nNodo eliminado: "<<aux->n<<endl;
							free(aux);
						}
						break;
					}
					else if(aux==ult)//determinamos si aux==ult
					{
						ult=ult->ant;
						if(ult==NULL)//Si solo habia un elemento
						{
							cab=NULL;
							cout<<"\nNodo eliminado: "<<aux->n<<endl;
							free(aux);
						}
						else//si habia mas de un elemento
						{
							ult->sig=NULL;
							aux->ant=NULL;
							cout<<"\nNodo eliminado: "<<aux->n<<endl;
							free(aux);
						}
						break;
					}
					else //O si solo es un elemento mas de la lista
					{
						aux2=aux->ant;
						aux2->sig=aux->sig;
						aux2=aux2->sig;
						aux2->ant=aux->ant;
						aux->sig=NULL;
						aux->ant=NULL;
						free(aux);
						break;
					}
					
				}
			case 11://Eliminar nodo del inicio
				{
					aux=cab;
					if(cab==NULL)
					{
						cout<<"La fila esta vacia..."<<endl;
					}
					else
					{
						cab=cab->sig;
						if(cab==NULL)
						{
							ult=NULL;
							cout<<"\nNodo eliminado: "<<aux->n<<endl;
							free(aux);
						}
						else
						{
							cab->ant=NULL;
							aux->sig=NULL;
							cout<<"\nNodo eliminado: "<<aux->n<<endl;
							free(aux);
						}
					}
					break;
				}
			case 12://Eliminar nodo del final
				{
					aux=ult;
					if(ult==NULL)
					{
						cout<<"La fila esta vacia..."<<endl;
					}
					else
					{
						ult=ult->ant;
						if(ult==NULL)
						{
							cab=NULL;
							cout<<"\nNodo eliminado: "<<aux->n<<endl;
							free(aux);
						}
						else
						{
							ult->sig=NULL;
							aux->ant=NULL;
							cout<<"\nNodo eliminado: "<<aux->n<<endl;
							free(aux);
						}
					}
					break;
				}
			case 10: 
					break;
					
			default:
					break;
		}
	}while(op != 10);
}

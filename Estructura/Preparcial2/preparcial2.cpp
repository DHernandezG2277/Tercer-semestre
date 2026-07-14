#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

struct cliente
{
int edad;
char nombre[20];
cliente *sig;
};

int main()
{
	cliente *rear_pref, *rear_normal, *rear_descarte, *rear_ext, *p, *front_pref, *front_normal, *front_descarte, *front_ext, *aux;
	int op;
	FILE *f;
	front_pref=rear_pref=front_normal=rear_normal=front_descarte=rear_descarte=front_ext=rear_ext=p=aux=NULL;
	do
	{
		cout<<"\n\n1. Cargar fila externa\n2. Mostrar fila externa\n3. Abrir banco\n4. Mostrar filas de adentro\n10. Salir\n Opcion: ";
		cin>>op;
		
		switch(op)
		{
			case 1:
				{
					f= fopen("clientes.txt", "r");
					p= (cliente *) malloc(sizeof(struct cliente));
					while(fscanf(f, "%s %d", p->nombre, &p->edad) == 2)
					{
						if(front_ext==NULL)
						{
							front_ext=rear_ext=p;
							p->sig=NULL;
						}
						else
						{
							rear_ext->sig=p;
							rear_ext=p;
							p->sig=NULL;
						}
						p= (cliente *) malloc(sizeof(struct cliente));
					}
					free(p);
					fclose(f);
					break;
				}
			case 2:
				{
					aux=front_ext;
					cout<<"\nEn la fila afuera del banco estan: "<<endl;
					while(aux!=NULL)
					{
						cout<<aux->nombre<<"		"<<aux->edad<<endl;
						aux=aux->sig;
					}
					break;
				}
			case 3:
				{
					aux=front_ext;
					rear_ext=rear_ext->sig;
					while(front_ext!=NULL)
					{
						aux=front_ext;
						front_ext=front_ext->sig;
						p= (cliente *) malloc(sizeof(struct cliente));
						p->edad=aux->edad;
						strcpy(p->nombre, aux->nombre);
						if(p->edad >= 18)
							{
								if(p->edad >= 63)// fila preferencial
								{
									if(front_pref == NULL)// si la fila esta vacia 
									{
										front_pref=rear_pref=p;
										p->sig=NULL;
									}
									else
									{
										rear_pref->sig=p;
										rear_pref=p;
										p->sig=NULL;
									}
								}
								else // fila normal / general
								{
									if(front_normal == NULL)// La fila esta vacia
									{
										front_normal=rear_normal=p;
										p->sig=NULL;
									}
									else
									{
										rear_normal->sig=p;
										rear_normal=p;
										p->sig=NULL;
									}
								}
							}
							else//fila de descarte
							{
								if(front_descarte == NULL)//fila vacia
								{
									front_descarte=rear_descarte=p;
									p->sig=NULL;
								}
								else
								{
									rear_descarte->sig=p;
									rear_descarte=p;
									p->sig=NULL;
								}
							}
						free(aux);
					}
					rear_ext=NULL;
					break;
				}
			case 4:
				{
					aux=front_normal;
					cout<<"\n\nEn la fila general se encuentran: "<<endl;
					while(aux!=NULL)
					{
						cout<<aux->nombre<<"		"<<aux->edad<<endl;
						aux=aux->sig;
					}
					aux=front_pref;
					cout<<"\n\nEn la fila preferencial se encuentran: "<<endl;
					while(aux!=NULL)
					{
						cout<<aux->nombre<<"		"<<aux->edad<<endl;
						aux=aux->sig;
					}
					aux=front_descarte;
					cout<<"\n\nClientes no validos para ingreso son: "<<endl;
					while(aux!=NULL)
					{
						cout<<aux->nombre<<"		"<<aux->edad<<endl;
						aux=aux->sig;
					}
					break;
			case 10:
					break;
			default:
					break;
				}
		}
	}while(op!=10);
}

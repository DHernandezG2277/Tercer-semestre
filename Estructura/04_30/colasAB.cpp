#include <iostream>
#include <stdlib.h>
using namespace std;

struct numero
{
int n;
numero *sig;	
};

int main()
{
	numero *frontA, *frontB, *rearA, *rearB, *p, *aux, *frontMIX, *rearMIX, *a, *b, *q;
	int op, contA, contB, mayor;
	op=contA=contB=mayor=0;
	frontA=frontB=frontMIX=rearA=rearB=rearMIX=NULL;
	do
	{
		cout<<"\n1. Cargar cola A\n2. Cargar cola B\n3. Mostrar colas\n4. Combinar colas\n10. Salir\n\n Opcion: ";
		cin>>op;
		switch(op)
		{
			case 1:
					do 
					{
						p=(numero *) malloc(sizeof(struct numero));
						cout<<"\nIngrese numero entero: ";
						cin>>p->n;
						
						if(frontA==NULL)
						{
							frontA=rearA=p;
							p->sig=NULL;
						}
						
						else if(p->n > rearA->n)
						{
							rearA->sig=p;
							rearA=p;
							p->sig=NULL;
						}
						else
							break;
					}while(true);
					break;
			case 2:
					do 
					{
						p=(numero *) malloc(sizeof(struct numero));
						cout<<"\nIngrese numero entero: ";
						cin>>p->n;
						
						if(frontB==NULL)
						{
							frontB=rearB=p;
							p->sig=NULL;
						}
						
						else if(p->n > rearB->n)
						{
							rearB->sig=p;
							rearB=p;
							p->sig=NULL;
						}
						else
							break;
					}while(true);
					break;
			case 3:
					aux=frontA;
					cout<<"\nLa pila ingresada A es: "<<endl;
					while(aux!=NULL)
					{
						cout<<" "<<aux->n;
						aux=aux->sig;
					}
					cout<<"\nLa pila ingresada B es: "<<endl;
					aux=frontB;
					while(aux!=NULL)
					{
						cout<<" "<<aux->n;
						aux=aux->sig;
					}
					aux=frontMIX;
					cout<<"\nLa cola combinada es: "<<endl;
					while(aux!=NULL)
					{
						cout<<" "<<aux->n;
						aux=aux->sig;
					}
				
					break;
			case 4:
					contA=contB=mayor=0;
					frontMIX=rearMIX=NULL;
					a=frontA;
					b=frontB;
					aux=a;
					while(aux!=NULL)
					{
						contA++;
						aux=aux->sig;
					}
					aux=b;
					while(aux!=NULL)
					{
						contB++;
						aux=aux->sig;
					}
					if(contA>=contB)
						mayor=contA;
					else
						mayor=contB;
					
					while(a!=NULL && b!=NULL)
					{
					
						if(a->n < b->n)
						{
							p=(numero *) malloc(sizeof(struct numero));
							p->n=a->n;
							p->sig=NULL;
							q=(numero *) malloc(sizeof(struct numero));
							q->n=b->n;
							q->sig=NULL;
							a=a->sig;
							b=b->sig;
							if(frontMIX==NULL)
							{
								frontMIX=rearMIX=p;
								p->sig=q;
								rearMIX=q;
								q->sig=NULL;
							}
							
							else
							{
								rearMIX->sig=p;
								p->sig=q;
								rearMIX=q;
								q->sig=NULL;
							}
						}
						else if(b->n < a->n)
						{
							p=(numero *) malloc(sizeof(struct numero));
							p->n=b->n;
							p->sig=NULL;
							q=(numero *) malloc(sizeof(struct numero));
							q->n=a->n;
							q->sig=NULL;
							a=a->sig;
							b=b->sig;
							if(frontMIX==NULL)
							{
								frontMIX=rearMIX=p;
								p->sig=q;
								rearMIX=q;
								q->sig=NULL;
							}
							
							else
							{
								rearMIX->sig=p;
								p->sig=q;
								rearMIX=q;
								q->sig=NULL;
							}
						}
						else
						{
							p=(numero *) malloc(sizeof(struct numero));
							p->n=b->n;
							p->sig=NULL;
							a=a->sig;
							b=b->sig;
							if(frontMIX==NULL)
								frontMIX=rearMIX=p;
							
							else
							{
								rearMIX->sig=p;
								rearMIX=p;
							}
						}
					}
					
					while(a!=NULL)
					{
						p=(numero *) malloc(sizeof(struct numero));
						p->n=a->n;
						p->sig=NULL;
						rearMIX->sig=p;
						rearMIX=p;
						a=a->sig;
					}
					
					while(b!=NULL)
					{
						p=(numero *) malloc(sizeof(struct numero));
						p->n=b->n;
						p->sig=NULL;
						rearMIX->sig=p;
						rearMIX=p;
						b=b->sig;
					}
					aux=frontMIX;
					cout<<"La cola combinada es: "<<endl;
					while(aux!=NULL)
					{
						cout<<" "<<aux->n;
						aux=aux->sig;
					}
					break;
			case 10:
					break;
			default:
					break;
		}
	}while(op!=10);
}

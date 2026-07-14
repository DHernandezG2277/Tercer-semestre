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
					cout<<"\nLa cola ingresada A es: "<<endl;
					while(aux!=NULL)
					{
						cout<<" "<<aux->n;
						aux=aux->sig;
					}
					cout<<"\nLa cola ingresada B es: "<<endl;
					aux=frontB;
					while(aux!=NULL)
					{
						cout<<" "<<aux->n;
						aux=aux->sig;
					}
					break;
			case 4:
					contA=contB=mayor=0;        // FIX: reiniciar contadores
					frontMIX=rearMIX=NULL;      // FIX: reiniciar cola MIX
					a=frontA;
					b=frontB;

					// --- FASE 1: mientras ambas colas tengan nodos ---
					while(a!=NULL && b!=NULL)   // FIX: reemplaza el for+break
					{
						p=(numero *) malloc(sizeof(struct numero));

						if(a->n < b->n)
						{
							p->n=a->n;
							a=a->sig;
						}
						else if(b->n < a->n)
						{
							p->n=b->n;
							b=b->sig;
						}
						else                    // FIX: iguales, tomar uno y avanzar ambos
						{
							p->n=a->n;
							a=a->sig;
							b=b->sig;
						}

						p->sig=NULL;

						if(frontMIX==NULL)
						{
							frontMIX=rearMIX=p;
						}
						else
						{
							rearMIX->sig=p;
							rearMIX=p;
						}
					}

					// --- FASE 2: sobran nodos en A ---
					while(a!=NULL)              // FIX: procesa el remanente de A
					{
						p=(numero *) malloc(sizeof(struct numero));
						p->n=a->n;
						p->sig=NULL;
						rearMIX->sig=p;
						rearMIX=p;
						a=a->sig;
					}

					// --- FASE 3: sobran nodos en B ---
					while(b!=NULL)              // FIX: procesa el remanente de B
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
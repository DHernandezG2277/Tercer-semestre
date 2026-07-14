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
	numero *front, *rear, *p, *aux;
	int op=0;
	front=NULL;
	rear=NULL;
	do
	{
		cout<<"\n1. Enqueue\n2. Denqueue\n3. mostrar cola\n10. Salir\n\n Opcion: ";
		cin>>op;
		switch(op)
		{
			case 1:
					p=(numero *) malloc(sizeof(struct numero));
						cout<<"\nIngrese numero entero: ";
						cin>>p->n;
					
					if(front==NULL)
					{
						front=rear=p;
						p->sig=NULL;
					}
					else
					{
						rear->sig=p;
						rear=p;
						p->sig=NULL;
					}
					break;
			case 2:
					if(front==NULL)
						cout<<"\nLa lista esta vacia..."<<endl;
					else if(front->sig==NULL)
						{
							p=front;
							cout<<"Se atendio a: "<<p->n<<endl;
							front=front->sig;
							rear=rear->sig;
							free(p);
						}
						else
						{
							p=front;
							cout<<"Se atendio a: "<<p->n<<endl;
							front=front->sig;
							/*Por problema se realiza una correccion:
							if(front==rear) //mismo condicional que use en la parte anterior
								front=rear=NULL;
							*/
							free(p);
						}
					break;
			case 3:
					aux=front;
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

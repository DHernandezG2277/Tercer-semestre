#include<iostream>
#include<stdlib.h>
using namespace std;

/*
1. agregar nodo final
2. agregar nodo al inicio
3. mostrar la lista
4. promediar datos
5. buscar un dato -- el 7 esta 3 veces || el 7 no esta en la lista
*/

struct nodo
{
	int n;
	nodo *sig;	
};

int main()
{
	nodo *cab, *ult, *p, *aux;
	int op;
	cab=ult=NULL;
	do
	{
		cout<<"\n1. Agregar nodo\n2. Mostrar lista\n10. Salir\n\n opcion:";
		cin>>op;
		switch(op)
		{
			case 1: 
					p=(nodo *)  malloc(sizeof(struct nodo));
					cout<<"Ingrese un valor: ";
					cin>>p->n;
					if(cab==NULL)
						{
							cab=ult=p;
							p->sig=NULL;
						}
					else
						{
							ult->sig=p;
							p->sig=NULL;
							ult=p;
						}
					break;
			case 2:
					aux=cab;
					cout<<"La lista ingresada es: "<<endl;
					while(aux!=NULL)
					{
						cout<<" "<<aux->n;
						aux=aux->sig;
					}
					cout<<endl;
					break;
			case 10:
					break;
			default: 
					break;	
		}
	}while(op!=10);
}

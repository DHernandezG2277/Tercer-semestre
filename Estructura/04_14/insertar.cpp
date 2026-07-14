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
	int op, acu=0, cont=0, numero=0, cont2=0, a;
	float prom;
	cab=ult=NULL;
	do
	{
		cout<<"\n1. Agregar nodo al final\n2. Agregar nodo al comienzo\n3. mostrar lista\n4. Promediar datos\n5. buscar un dato\n6. Insertar\n10. Salir\n\n opcion:";
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
							p->sig= cab;
							cab=p;
						}
					break;
			case 3:
					aux=cab;
					cout<<"La lista ingresada es: "<<endl;
					while(aux!=NULL)
					{
						cout<<" "<<aux->n;
						aux=aux->sig;
					}
					cout<<endl;
					break;
			case 4:
					aux=cab;
					cont=0;
					while(aux!=NULL)
					{
						acu += aux->n;
						cont++;
						aux=aux->sig;
					}
					prom= (float)acu/cont;
					cout<<"El promedio de los datos ingresados es: "<<prom<<endl;
					break;
			case 5: 
					aux=cab;
					cont=0;
					cont2=0;
					cout<<"Ingrese el numero a buscar: ";
					cin>>numero;
					while(aux!=NULL)
					{
						cont++;
						if(numero==aux->n)
						{
							cout<<"El numero "<<numero<<" fue encontrado en la posicion "<<cont<<endl;
							cont2++;
						}
						else if(aux->sig==NULL && cont2==0)
						{
							cout<<"El numero ingresado no se encuentra en la lista"<<endl;
						}
						aux=aux->sig;
					}
					break;
			case 6:
					cout<<"Delante de quien?: ";
					cin>>a;
					aux=cab;
					while(aux!=NULL)
						{
							if(aux->n==a)
								break;
							else
								aux=aux->sig;
						}
					if(aux->sig==NULL)
						{
							cout<<"No se puede agregar valor en la posicion seleccionada"<<endl;
							break;	
						}
					else
						{
						if(aux==NULL)
							cout<<"La posicion ingresada no se encuentra"<<endl;
						else
							{
								p=(nodo *)  malloc(sizeof(struct nodo));
								cout<<"Ingrese un valor a insertar: ";
								cin>>p->n;
								p->sig=aux->sig;
								aux->sig=p;
								cout<<"Dato insertado"<<endl;
							}
						break;
						}
			case 10:
					break;
			default: 
					break;
		}
	}while(op!=10);
}

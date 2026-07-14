#include<iostream>
#include<stdlib.h>
using namespace std;

struct nodo
{
	int n;
	nodo *sig;	
};

int main()
{
	nodo *tope_A, *p, *aux_A, *tope_B, *aux_B, *ult_A, *ult_B;
	int op, cont_A=0, cont_B=0, suma_A=0, suma_B=0;
	float prom_A, prom_B;
	tope_A=NULL;
	tope_B=NULL;
	do
	{
		cout<<"\n1. Push A\n2. Pop A\n3. Mostrar pila A\n4. Push B\n5. Pop B\n6. Mostrar pila B\n7. Reporte Filas\n8. Unir pilas\n9. salir\n opcion:";
		cin>>op;
		switch(op)
		{
			case 1: 
					p=(nodo *)  malloc(sizeof(struct nodo));
					cout<<"Push: ";
					cin>>p->n;
					if(tope_A==NULL)
						{
							tope_A=ult_A=p;
							p->sig=NULL;
						}
					else
						{
							p->sig=tope_A;
							tope_A=p;
						}
					break;
			case 2:
					if(tope_A==NULL)
						cout<<"La pila esta vacia"<<endl;
					else
					{
						aux_A=tope_A;
						tope_A=tope_A->sig;
						cout<<"Pop "<<aux_A->n<<endl;
						free(aux_A);
					}
					break;
			case 3:
					aux_A=tope_A;
					cout<<"\nLa pila es: "<<endl;
					while(aux_A!=NULL)
					{
						cout<<" "<<aux_A->n;
						aux_A=aux_A->sig;
					}
					cout<<endl;
					free(aux_A);
					break;
			case 4:
					p=(nodo *)  malloc(sizeof(struct nodo));
					cout<<"Push: ";
					cin>>p->n;
					if(tope_B==NULL)
						{
							tope_B=ult_B=p;
							p->sig=NULL;
						}
					else
						{
							p->sig=tope_B;
							tope_B=p;
						}
					break;
			case 5:
					if(tope_B==NULL)
						cout<<"La pila esta vacia"<<endl;
					else
					{
						aux_B=tope_B;
						tope_B=tope_B->sig;
						cout<<"Pop "<<aux_B->n<<endl;
						free(aux_B);
					}
					break;
			case 6:
					aux_B=tope_B;
					cout<<"La pila es: "<<endl;
					while(aux_B!=NULL)
					{
						cout<<" "<<aux_B->n;
						aux_B=aux_B->sig;
					}
					free(aux_B);
					cout<<endl;
					break;
					
			case 7: 
					aux_A=tope_A;
					aux_B=tope_B;
					while(aux_A!=NULL)
					{
						suma_A+=aux_A->n;
						aux_A=aux_A->sig;
						cont_A++;						
					}
					while(aux_B!=NULL)
					{
						suma_B+=aux_B->n;
						aux_B=aux_B->sig;
						cont_B++;						
					}
					prom_B=(float)suma_B/cont_B;
					prom_A=(float)suma_A/cont_A;
					cout<<"\nPila A: "<<endl;
					cout<<"Cantidad de elementos: "<<cont_A<<endl;
					cout<<"Suma de elementos: "<<suma_A<<endl;
					cout<<"Promedio de elementos: "<<prom_A<<endl;
					
					cout<<"\n\nPila B: "<<endl;
					cout<<"Cantidad de elementos: "<<cont_B<<endl;
					cout<<"Suma de elementos: "<<suma_B<<endl;
					cout<<"Promedio de elementos: "<<prom_B<<endl;
					break;
			case 8:
					aux_A=tope_A;
					aux_B=tope_B;
					cont_A=0;
					cont_B=0;
					while(aux_A!=NULL)
					{
						cont_A++;
						aux_A=aux_A->sig;
					}
					while(aux_B!=NULL)
					{
						cont_B++;
						aux_B=aux_B->sig;
					}
					if(cont_A>=cont_B)
					{
						for(int i=0; i<cont_B; i++)
						{
							if(tope_B == ult_B)
				            {
				                p = ult_B;
				                tope_B = NULL;
				                ult_B = NULL;
				            }
				            else
				            {
								aux_B=tope_B;
								while(aux_B->sig!=ult_B)
								{
									aux_B=aux_B->sig;
								}
								p= ult_B;
								aux_B->sig= NULL;
								ult_B=aux_B;
							}
							p->sig = tope_A;
            				tope_A = p;
						}
        				aux_A=tope_A;
						cout<<"\nLa pila combinada A es: "<<endl;
						while(aux_A!=NULL)
						{
							cout<<" "<<aux_A->n;
							aux_A=aux_A->sig;
						}
						cout<<endl;
					}
					else
					{
						for(int i=0; i<cont_A; i++)
						{
							if(tope_A == ult_A)
					        {
				                p = ult_A;
				                tope_A = NULL;
				                ult_A = NULL;
					    	}
					        else
					        {
								aux_A=tope_A;
								while(aux_A->sig!=ult_A)
								{
									aux_A=aux_A->sig;
								}
								p= ult_A;
								aux_A->sig= NULL;
								ult_A=aux_A;
							}
							p->sig = tope_B;
            				tope_B = p;
						}
        				aux_B=tope_B;
						cout<<"\nLa pila combinada B es: "<<endl;
						while(aux_B!=NULL)
						{
							cout<<" "<<aux_B->n;
							aux_B=aux_B->sig;
						}
						cout<<endl;
					}
					break;
			case 9:
					break;
			default: 
					break;
		}
	}while(op!=9);
}

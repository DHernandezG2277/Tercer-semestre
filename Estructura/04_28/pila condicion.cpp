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
	numero *p, *cabA, *aux, *cabB, *cabC, *a, *b, *c, *mix;
	int op;
	cabA=NULL;
	cabB=NULL;
	cabC=NULL;
	a=NULL;
	b=NULL;
	c=NULL;
	do
	{
		cout<<"\n1. Cargar pila A\n2. Cargar pila B\n3. Cargar pila C\n4. Mostrar pila\n5. Combinar pilas\n10. Salir\n\n opcion: ";
		cin>>op;
		
		switch(op)
		{
			case 1:
					do 
					{
						p=(numero *) malloc(sizeof(struct numero));
						cout<<"\nIngrese numero entero: ";
						cin>>p->n;
						
						if(cabA==NULL)
						{
							cabA=p;
							p->sig=NULL;
						}
						
						else if(p->n > cabA->n)
						{
							p->sig=cabA;
							cabA=p;
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
						
						if(cabB==NULL)
						{
							cabB=p;
							p->sig=NULL;
						}
						
						else if(p->n > cabB->n)
						{
							p->sig=cabB;
							cabB=p;
						}
						else
							break;
					}while(true);
					break;
			case 3:
					do 
					{
						p=(numero *) malloc(sizeof(struct numero));
						cout<<"\nIngrese numero entero: ";
						cin>>p->n;
						
						if(cabC==NULL)
						{
							cabC=p;
							p->sig=NULL;
						}
						
						else if(p->n > cabC->n)
						{
							p->sig=cabC;
							cabC=p;
						}
						else
							break;
					}while(true);
					break;
			case 4:
					aux=cabA;
					cout<<"\nLa pila ingresada A es: "<<endl;
					while(aux!=NULL)
					{
						cout<<" "<<aux->n;
						aux=aux->sig;
					}
					
					aux=cabB;
					cout<<"\nLa pila ingresada B es: "<<endl;
					while(aux!=NULL)
					{
						cout<<" "<<aux->n;
						aux=aux->sig;
					}
					
					aux=cabC;
					cout<<"\nLa pila ingresada C es: "<<endl;
					while(aux!=NULL)
					{
						cout<<" "<<aux->n;
						aux=aux->sig;
					}
					
					cout<<endl;
					break;
					
			case 5:
					a=cabA;
					b=cabB;
					c=cabC;
					do
					{
						if(a->n > b->n)
						{
							if(b->n < c->n)
							{
								if(a->n > c->n)
									// a > c > b
								{
									
									
									if(mix==NULL)
									{
										p=a;
										a=a->sig;
										cabA= cabA->sig;
										mix=p;
										mix->sig=NULL;
										//////
										p=c;
										c=c->sig;
										cabC= cabC->sig;
										p->sig= mix;
										mix=p;
										//////
										p=b;
										b=b->sig;
										cabB= cabB->sig;
										p->sig= mix;
										mix=p;
										free(p);
									}
									
									else
									{
										p=a;
										a=a->sig;
										cabA= cabA->sig;
										p->sig= mix;
										mix=p;
										/////
										p=c;
										c=c->sig;
										cabC= cabC->sig;
										p->sig= mix;
										mix=p;
										//////
										p=b;
										b=b->sig;
										cabB= cabB->sig;
										p->sig= mix;
										mix=p;
									}
								}
								else
									// c > a > b
								{
									if(mix==NULL)
									{
										p=c;
										c=c->sig;
										cabC= cabC->sig;
										mix=p;
										mix->sig=NULL;
										//////
										p=a;
										a=a->sig;
										cabA= cabA->sig;
										p->sig= mix;
										mix=p;
										//////
										p=b;
										b=b->sig;
										cabB= cabB->sig;
										p->sig= mix;
										mix=p;
										free(p);
									}
									
									else
									{
										p=c;
										c=c->sig;
										cabC= cabC->sig;
										p->sig= mix;
										mix=p;
										/////
										p=a;
										a=a->sig;
										cabA= cabA->sig;
										p->sig= mix;
										mix=p;
										//////
										p=b;
										b=b->sig;
										cabB= cabB->sig;
										p->sig= mix;
										mix=p;
									}
								}
							}
							else
								//a > b > c
							{
								if(mix==NULL)
								{
									{
										p=a;
										a=a->sig;
										cabA= cabA->sig;
										mix=p;
										mix->sig=NULL;
										//////
										p=b;
										b=b->sig;
										cabB= cabB->sig;
										p->sig= mix;
										mix=p;
										//////
										p=c;
										c=c->sig;
										cabC= cabC->sig;
										p->sig= mix;
										mix=p;
										free(p);
										
									}
								}
									
								else
								{
									p=a;
									a=a->sig;
									cabA= cabA->sig;
									p->sig= mix;
									mix=p;
									/////
									p=b;
									b=b->sig;
									cabB= cabB->sig;
									p->sig= mix;
									mix=p;
									//////
									p=c;
									c=c->sig;
									cabC= cabC->sig;
									p->sig= mix;
									mix=p;
								}
							}
						}
						else if(b->n > a->n)
							{
								if(a->n < c->n)
								{
									if(b->n > c->n)
										// b > c > a
									{
										if(mix==NULL)
										{
											p=b;
											b=b->sig;
											cabB= cabB->sig;
											mix=p;
											mix->sig=NULL;
											//////
											p=c;
											c=c->sig;
											cabC= cabC->sig;
											p->sig= mix;
											mix=p;
											//////
											p=a;
											a=a->sig;
											cabA= cabA->sig;
											p->sig= mix;
											mix=p;
											free(p);
											
										}
										
										else
										{
											p=b;
											b=b->sig;
											cabB= cabB->sig;
											p->sig= mix;
											mix=p;
											/////
											p=c;
											c=c->sig;
											cabC= cabC->sig;
											p->sig= mix;
											mix=p;
											//////
											p=a;
											a=a->sig;
											cabA= cabA->sig;
											p->sig= mix;
											mix=p;
										}
									}
									else
										// c > b > a
									{
											if(mix==NULL)
										{
											p=c;
											c=c->sig;
											cabC= cabC->sig;
											mix=p;
											mix->sig=NULL;
											//////
											p=b;
											b=b->sig;
											cabB= cabB->sig;
											p->sig= mix;
											mix=p;
											//////
											p=a;
											a=a->sig;
											cabA= cabA->sig;
											p->sig= mix;
											mix=p;
											free(p);
											
										}
										
										else
										{
											p=c;
											c=c->sig;
											cabC= cabC->sig;
											p->sig= mix;
											mix=p;
											/////
											p=b;
											b=b->sig;
											cabB= cabB->sig;
											p->sig= mix;
											mix=p;
											//////
											p=a;
											a=a->sig;
											cabA= cabA->sig;
											p->sig= mix;
											mix=p;
										}
									}
								}
								else
									// b > a > c
								{
									if(mix==NULL)
									{
										p=b;
										b=b->sig;
										cabB= cabB->sig;
										mix=p;
										mix->sig=NULL;
										//////
										p=a;
										a=a->sig;
										cabA= cabA->sig;
										p->sig= mix;
										mix=p;
										//////
										p=c;
										c=c->sig;
										cabC= cabC->sig;
										p->sig= mix;
										mix=p;
										free(p);
										
									}
									
									else
									{
										p=b;
										b=b->sig;
										cabB= cabB->sig;
										p->sig= mix;
										mix=p;
										/////
										p=a;
										a=a->sig;
										cabA= cabA->sig;
										p->sig= mix;
										mix=p;
										//////
										p=c;
										c=c->sig;
										cabC= cabC->sig;
										p->sig= mix;
										mix=p;
									}
								}
							}
					}while((a || b || c)!=NULL);
					if (a || b || c==NULL)
						cout<<"Sale"<<endl;
					aux=mix;
					cout<<"\nLa pila ingresada mix es: "<<endl;
					while(aux->sig!=NULL)
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

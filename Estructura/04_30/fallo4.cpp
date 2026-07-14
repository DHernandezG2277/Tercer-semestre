//funcion random
if(frontA==NULL)
						cout<<"\nLa lista esta vacia..."<<endl;
					else if(frontA->sig==NULL)
						{
							p=frontA;
							cout<<"Se atendio a: "<<p->n<<endl;
							frontA=frontA->sig;
							rearA=rearA->sig;
							free(p);
						}
						else
						{
							p=frontA;
							cout<<"Se atendio a: "<<p->n<<endl;
							/*Por problema se realiza una correccion:
							if(front==rear) //mismo condicional que use en la parte anterior
								front=rear=NULL;
							*/
							front=front->sig;
							free(p);
						}
						///////////// Cambio a B
					if(frontB==NULL)
						cout<<"\nLa lista esta vacia..."<<endl;
					else if(frontB->sig==NULL)
						{
							p=frontB;
							cout<<"Se atendio a: "<<p->n<<endl;
							frontB=frontB->sig;
							rearB=rearB->sig;
							free(p);
						}
						else
						{
							p=frontB;
							cout<<"Se atendio a: "<<p->n<<endl;
							/*Por problema se realiza una correccion:
							if(front==rear) //mismo condicional que use en la parte anterior
								front=rear=NULL;
							*/
							frontB=frontB->sig;
							free(p);
						}
					break;

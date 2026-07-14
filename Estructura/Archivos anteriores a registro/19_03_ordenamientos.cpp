#include <iostream>
using namespace std;

main()
{
	int vec[8], pm, aux;
	for(int i=0; i<8; i++)
	{
		cout<<"Ingrese dato de la posicion "<<i<<": ";
		cin>>vec[i];
	}
	for(int i=0; i<7; i++)
	{
		pm=i;
		for(int j=i+1; j<8; j++)
		{
			if(vec[j]<vec[pm])
				pm=j;
		}
		aux=vec[i];
		vec[i]= vec[pm];
		vec[pm]= aux;
		cout<<"\nIteracion "<<i<<": ";
		for(int k=0; k<8; k++)
			cout<<" "<<vec[k];
	}
	
}

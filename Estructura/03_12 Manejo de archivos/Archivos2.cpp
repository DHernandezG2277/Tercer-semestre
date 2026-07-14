#include <iostream>
using namespace std;

void Proceso()
{
	int n;
	FILE *p;
	p= fopen("Datos.txt", "w");
	cout<<"Ingrese entero positivo: ";
	cin>>n;
	while(n>0)
	{
		fprintf(p, " %d",n);
		cout<<"ingrese entero positivo: ";
		cin>>n;	
	}
	fclose(p);
}

int main()
{
	Proceso();
	return 0;
}

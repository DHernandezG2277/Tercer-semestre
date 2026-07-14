#include <iostream>
using namespace std;

void Proceso()
{
	FILE *p;
	int n, prom=0, cont=0;
	float resultado=0.0;
	if(p=fopen("datos.txt","r"))
	{
	cout<<"El promedio entre los numeros ";
		while(!feof(p))
		{
			fscanf(p,"%d", &n);
			cout<<" "<<n;
			prom += n;
			cont++;
		}
	fclose(p);
	
	resultado = prom/ (float)cont;
		
	cout<<" es: "<<resultado<<endl;
	}
	
	else
	cout<<"El archivo no se pudo abrir";
}

int main()
{
	Proceso();
	return 0;
}

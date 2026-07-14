#include <iostream>
using namespace std;

void Proceso()
{
	int n;
	FILE *p, *imp, *par;
	if( (p= fopen("numeros.txt", "r")) && (imp= fopen("impares.txt", "w")) && (par= fopen("pares.txt", "w")))
	{
		
		while(!feof(p))
		{
			fscanf(p, " %d", &n);
			if(n%2 == 0)
				fprintf(par, " %d", n);
			else
				fprintf(imp, " %d", n);	
		}
		fclose(p);
		fclose(par);
		fclose(imp);
	}
}

int main()
{
	Proceso();
	return 0;
}

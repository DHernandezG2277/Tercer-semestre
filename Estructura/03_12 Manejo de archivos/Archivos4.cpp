#include <iostream>
using namespace std;

void Proceso()
{
	int cod, n1, n2, n3;
	FILE *p, *Aprobado, *Reprobado;
	char nombre[20];
	float N_Final;
	
	p=fopen("Notas.txt", "r");
	Aprobado= fopen("Aprobados.txt", "w");
	Reprobado= fopen("Reprobados.txt", "w");
	
	while(!feof(p))
	{
		fscanf(p, "%d %s %d %d %d", &cod, &nombre, &n1, &n2, &n3);
		N_Final= float(n1 + n2 + n3)/3;
		if(N_Final>=30.0)
			fprintf(Aprobado, "%d %s %f\n", cod, nombre, N_Final);
		else
			fprintf(Reprobado, "%d %s %f\n", cod, nombre, N_Final);
	}
	
	fclose(p);
	fclose(Aprobado);
	fclose(Reprobado);
}

int main()
{
	Proceso();
	return 0;
}

#include <iostream>
using namespace std;

struct Estudiante
{
    char nombre[20];
    int codigo;
    float promedio;
};

int main()
{
  Estudiante Curso[12];
  int op, i=0, contador=0;
  FILE *p;
  
  do
  {
    cout<<"\nCargando.....\n\n1. Cargar datos\n2. Mostrar datos\n3. Informacion del promedio mayor y menor\n4. Promedio del curso\n5. Listado de estudiantes aprobados\n10. salir...\n Opcion:";
    cin>>op;
    switch (op)
    {
    case 1:
    		i=0;
    		contador=0;
    		p= fopen("estudiantes.txt","r");
        	while(!feof(p))
        	{
        		fscanf(p, "%d %s %f", &Curso[i].codigo, &Curso[i].nombre, &Curso[i].promedio);
        		contador++;
        		i++;
			}
			cout<<"\n\nEstudiantes cargados :)"<<endl;
        break;
    case 2: 
        cout<<"\n\nLos datos ingresados fueron: "<<endl;
        for(i=0; i<contador; i++)
            cout<<"Codigo: "<<Curso[i].codigo<<" Nombre: "<<Curso[i].nombre<<" Promedio: "<<Curso[i].promedio<<endl;
        break;
    case 3:
    	{
        Estudiante mayor= Curso[0], menor= Curso[0];
        for(i=0; i<contador; i++)
        {
            if (Curso[i].promedio > mayor.promedio)
            {
                mayor = Curso[i];
			}
            else if (Curso[i].promedio < menor.promedio)
                menor = Curso[i];
        }
        cout<<"\n\nEl promedio mayor del curso es: "<<endl;
        cout<<"Codigo: "<<mayor.codigo<<" Nombre: "<<mayor.nombre<<" Promedio: "<<mayor.promedio<<endl;
        cout<<"El promedio menor del curso es: "<<endl;
        cout<<"Codigo: "<<menor.codigo<<", Nombre: "<<menor.nombre<<" Promedio: "<<menor.promedio<<endl;
        break;
    	}
    case 4:
    	{
        float prom_curso, prom = 0;
        for(i=0; i<contador; i++)
            prom += Curso[i].promedio;
        prom_curso = prom / contador;
        cout<<"\n\nEl promedio del curso es: "<<prom_curso<<endl;
        break;
    	}
    case 5:
        cout<<"\n\nListado de estudiantes aprobados: "<<endl;
        for (int i = 0; i < contador; i++)
        {
            if (Curso[i].promedio >= 3.0)
                cout<<"Codigo: "<<Curso[i].codigo<<", Nombre: "<<Curso[i].nombre<<", Promedio: "<<Curso[i].promedio<<endl;
        }
        break;
    default:
        break;
    }
  } while (op != 10);
  return 0;
}

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
  Estudiante Curso[10];
  int op, i=0, contador=0, pm=0;
  FILE *p, *salida;
  float n1,n2,n3;
  
  do
  {
    cout<<"\nCargando.....\n\n1. Cargar datos\n2. Mostrar datos\n3. Ordenar por nombre\n4. Ordenar por promedio\n5. Imprimir ultimo orden\n10. salir...\n Opcion:";
    cin>>op;
    switch (op)
    {
    case 1:
    		i=0;
    		contador=0;
    		p= fopen("notas.txt","r");
        	while(!feof(p))
        	{
        		fscanf(p, "%d %s %f %f %f", &Curso[i].codigo, Curso[i].nombre, &n1, &n2, &n3);
        		Curso[i].promedio= (n1+n2+n3)/3;
        		contador++;
        		i++;
			}
			fclose(p);
			cout<<"\n\nEstudiantes cargados :)"<<endl;
        break;
    case 2: 
        cout<<"\n\nLos datos ingresados fueron: "<<endl;
        for(i=0; i<contador; i++)
            cout<<"Codigo: "<<Curso[i].codigo<<" Nombre: "<<Curso[i].nombre<<" Promedio: "<<Curso[i].promedio<<endl;
        break;
    case 3:
    	{	
    		Estudiante aux;
        	for(i=0; i<contador-1; i++)
			{
				pm=i;
				for(int j=i+1; j<contador; j++)
				{
					if(Curso[j].nombre[0]<Curso[pm].nombre[0])
						pm=j;
				}
				aux=Curso[i];
				Curso[i]= Curso[pm];
				Curso[pm]= aux;
	    	}
	    	cout<<"\n\nLos datos ordenados por nombre son: "<<endl;
        	for(i=0; i<contador; i++)
            	if(Curso[i].codigo==Curso[i+1].codigo)
            	{
	            	cout<<"Codigo: "<<Curso[i+1].codigo<<" Nombre: "<<Curso[i+1].nombre<<" Promedio: "<<Curso[i+1].promedio<<endl;
	            	i++;
				}
	            else
	            	cout<<"Codigo: "<<Curso[i].codigo<<" Nombre: "<<Curso[i].nombre<<" Promedio: "<<Curso[i].promedio<<endl;
	    	break;
    	}
    case 4:
    	{
        Estudiante aux;
        	for(i=0; i<contador; i++)
			{
				for(int j=0; j<contador-i-1; j++)
				{
					if(Curso[j].promedio>Curso[j+1].promedio)
					{
						aux= Curso[j];
						Curso[j]= Curso[j+1];
						Curso[j+1]= aux;	
					}
				}
	    	}
	    	cout<<"\n\nLos datos ordenados por promedio son: "<<endl;
	        for(i=0; i<contador; i++)
	        {
	        	if(Curso[i].codigo==Curso[i+1].codigo)
	        	{
	            	cout<<"Codigo: "<<Curso[i+1].codigo<<" Nombre: "<<Curso[i+1].nombre<<" Promedio: "<<Curso[i+1].promedio<<endl;
	            	i++;
				}
	            else
	            	cout<<"Codigo: "<<Curso[i].codigo<<" Nombre: "<<Curso[i].nombre<<" Promedio: "<<Curso[i].promedio<<endl;
			}
        break;
    	}
    case 5:
    	salida= fopen("DanielHernandez.txt", "w");
    	for(i=0; i<contador; i++)
    	{
    		if(Curso[i].codigo==Curso[i+1].codigo)
    		{
    			fprintf(salida, "%d %s %f \n", Curso[i+1].codigo, Curso[i+1].nombre, Curso[i+1].promedio);
    			i++;
			}
			else
    			fprintf(salida, "%d %s %f \n", Curso[i].codigo, Curso[i].nombre, Curso[i].promedio);
		}
		cout<<"\nArchivo guardado\n";
		fclose(salida);
        break;
    default:
        break;
    }
  } while (op != 10);
  return 0;
}

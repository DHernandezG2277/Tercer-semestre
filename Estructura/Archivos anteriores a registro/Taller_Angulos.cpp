#include <iostream>
using namespace std;



int main()
{
	float x, num, term, seno = 0, coseno = 0, tangente = 0, secante = 0, cosecante = 0, cotangente = 0;
    int dem, op;
	    	cout << "digite el angulo que necesita: ";
	    	cin >> x;
	
	    x = (x * 3.1416) / 180;
	    for (int n = 0; n <= 4; n++)
	    {
	        num = dem = 1;
	        for (int i = 1; i <= 2 * n + 1; i++)
	        {
	            num = num * x;
	            dem = dem * i;
	        }
	        term = num / dem;
	        if (n % 2 == 1)
	        {
	            term = term * -1;
	        }
	        seno = seno + term;
	    }
	    for (int n = 0; n <= 4; n++)
	    {
	        num = dem = 1;
	        for (int i = 1; i <= 2 * n; i++)
	        {
	            num = num * x;
	            dem = dem * i;
	        }
	        term = num / dem;
	        if (n % 2 == 1)
	        {
	            term = term * -1;
	        }
	        coseno = coseno + term;
	    }
	    tangente = seno / coseno;
	    cotangente = 1 / tangente;
	    secante = 1 / coseno;
	    cosecante = 1 / seno;
			
		do
	    {
	        cout << "\n\n1. seno\n2. coseno\n3. tangente\n4. secante\n5. cosecante\n6. cotangente\n7. Todas las respuestas\n8. Ingresar otro angulo\n9. Salir\n";
	        cout << "digite el numero de la funcion que desea: ";
	        cin >> op;
	        cout<<endl<<endl;
	        switch (op)
	        {
	        case 1:
	            cout << "el seno es: " << seno;
	            break;
	        case 2:
	            cout << "el coseno es: " << coseno;
	            break;
	        case 3:
	            cout << "la tangente es: " << tangente;
	            break;
	        case 4:
	            cout << "la secante es: " << secante;
	            break;
	        case 5:
	            cout << "la cosecante es: " << cosecante;
	            break;
	        case 6:
	            cout << "la cotangente es: " << cotangente;
	            break;
	        case 7:
	        	cout << "el seno es: " << seno<<endl;
	        	cout << "el coseno es: " << coseno<<endl;
	        	cout << "la tangente es: " << tangente<<endl;
	        	cout << "la secante es: " << secante<<endl;
	        	cout << "la cosecante es: " << cosecante<<endl;
	        	cout << "la cotangente es: " << cotangente<<endl;
	        	break;
	        case 8:
	    		main();
	    		break;
	    	case 9:
	    		return 0;
	    		break;
	        default:
	            cout << "opcion no valida";
	            break;
	        }
	    } while (num != 9);
	
    
    return 0;
}

    
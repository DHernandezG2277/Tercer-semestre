#include <iostream>
using namespace std;

int main() {
    float alfa, x, seno = 0, coseno = 0, term;
    float PI = 3.1416;

	cout<<"Ingrese el angulo a calcular: ";
    cin >> alfa;                 
    x = alfa * PI / 180.0;       

    term = x;                    
    for (int n = 0; n <= 4; n++) {
        seno += term;
        for(int i=1, )
        term *= x / ((2*n + 2) * (2*n + 3));
        if(n%2!=0)
        {
        	termino = termino* -1;
		}
    }

    cout << seno << endl;
    
    for (int n = 0; n <= 4; n++) {
        coseno += term;
        term *= -x * x / ((2*n + 2) * (2*n + 3));  
    }
    
    return 0;
}

/*
void Proceso()
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
}*/
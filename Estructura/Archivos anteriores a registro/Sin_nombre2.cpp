#include <iostream>
using namespace std;

void ejercicio1(){
    for(int i=15;i<=32;i++) cout<<i<<endl;
    for(int i=32;i>=15;i--) cout<<i<<endl;
}

void ejercicio2(){
    int a,b;
    cin>>a>>b;

    for(int i=a;i<=b;i++) cout<<i<<endl;
    for(int i=b;i>=a;i--) cout<<i<<endl;
}

void ejercicio3(){
    int a,b,suma=0;
    cin>>a>>b;

    for(int i=a;i<=b;i++) suma+=i;

    cout<<suma<<endl;
}

void ejercicio4(){
    int num,pares=0,suma=0;

    while(pares<5){
        cin>>num;

        if(num%2==0){
            suma+=num;
            pares++;
        }
    }

    cout<<suma<<endl;
}

void ejercicio5(){
    int a,b,c;
    cin>>a>>b>>c;

    for(int i=b;i<=c;i++)
        if(i%a==0) cout<<i<<endl;
}

void ejercicio6(){
    int n,temp,cifras=0;
    cin>>n;

    temp=n;

    while(temp>0){
        temp/=10;
        cifras++;
    }

    cout<<cifras<<endl;
}

void ejercicio7(){
    int n,temp,suma=0;
    cin>>n;

    temp=n;

    while(temp>0){
        suma+=temp%10;
        temp/=10;
    }

    cout<<suma<<endl;
}

void ejercicio8(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        if(n%i==0) cout<<i<<endl;
}

void ejercicio9(){
    int n,cont=0;
    cin>>n;

    for(int i=1;i<=n;i++)
        if(n%i==0) cont++;

    cout<<cont<<endl;
}

void ejercicio10(){
    int n,cont=0;
    cin>>n;

    for(int i=1;i<=n;i++)
        if(n%i==0) cont++;

    if(cont==2) cout<<"Es primo"<<endl;
    else cout<<"No es primo"<<endl;
}

void ejercicio11(){
    int n;
    cin>>n;

    for(int i=2;i<n;i++){
        int d=0;

        for(int j=1;j<=i;j++)
            if(i%j==0) d++;

        if(d==2) cout<<i<<endl;
    }
}

void ejercicio12(){
    int n,suma=0;
    cin>>n;

    for(int i=2;i<n;i++){
        int d=0;

        for(int j=1;j<=i;j++)
            if(i%j==0) d++;

        if(d==2) suma+=i;
    }

    cout<<suma<<endl;
}

void ejercicio13(){
    int n;
    cin>>n;

    for(int i=1;i<=10;i++)
        cout<<n<<" x "<<i<<" = "<<n*i<<endl;
}

void ejercicio14(){
    int n;
    cin>>n;

    for(int j=1;j<=n;j++){
        for(int i=1;i<=10;i++)
            cout<<j<<" x "<<i<<" = "<<j*i<<endl;
    }
}

void ejercicio15(){
    int n,a=0,b=1,c;
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<a<<endl;
        c=a+b;
        a=b;
        b=c;
    }
}

void ejercicio16(){
    int a,b,n;
    cin>>a>>b>>n;

    cout<<a<<endl;
    cout<<b<<endl;

    for(int i=0;i<n-2;i++){
        int c=a+b;
        cout<<c<<endl;
        a=b;
        b=c;
    }
}

void ejercicio17(){
    int n,nuevo=0,pos=1;
    cin>>n;

    while(n>0){
        int dig=n%10;

        if(dig%2==0){
            nuevo=dig*pos+nuevo;
            pos*=10;
        }

        n/=10;
    }

    cout<<nuevo<<endl;
}

void ejercicio18(){
    int n,rev=0;
    cin>>n;

    while(n>0){
        rev=rev*10+(n%10);
        n/=10;
    }

    cout<<rev<<endl;
}

int main(){

    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio4();
    ejercicio5();
    ejercicio6();
    ejercicio7();
    ejercicio8();
    ejercicio9();
    ejercicio10();
    ejercicio11();
    ejercicio12();
    ejercicio13();
    ejercicio14();
    ejercicio15();
    ejercicio16();
    ejercicio17();
    ejercicio18();

}
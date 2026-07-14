#include<iostream>
using namespace std;

int main()
{
	int a, *p;
	float x, *q;
	a=10;
	x=2.5;
	p=&a;
	q=&x;
	
	cout<<"\na= "<<a<<"	&a = "<<&a<<endl;
	cout<<"\nx= "<<x<<"	&x = "<<&x<<endl;
	cout<<"\np= "<<p<<"	&p = "<<&p<<"	*p = "<<*p<<endl;
	cout<<"\nq= "<<q<<"	&q = "<<&q<<"	*q = "<<*q<<endl;
}

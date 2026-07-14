#include<iostream>
using namespace std;

int main()
{
	int a, b, c, *p, *q, *r;	
	float x, y, z, *s, *t, *u;
	
	a=7;
	b=a++;
	c=++a;
	x=(float)b/5;
	z=c+0.5;
	y= 2 * z;
	s=&a;
	p=&b;
	q=&c;
	t=&x;
	s=&y;
	t=&z
	
		
	cout<<"\na= "<<a<<"	&a = "<<&a<<endl;
	cout<<"\nb= "<<b<<"	&b = "<<&b<<endl;
	cout<<"\nc= "<<c<<"	&c = "<<&c<<endl;
	cout<<"\nx= "<<x<<"	&x = "<<&x<<endl;
	cout<<"\ny= "<<y<<"	&y = "<<&y<<endl;
	cout<<"\nz= "<<z<<"	&z = "<<&z<<endl;
	
	
	cout<<"\np= "<<p<<"	&p = "<<&p<<"	*p = "<<*p<<endl;
	cout<<"\nq= "<<q<<"	&q = "<<&q<<"	*q = "<<*q<<endl;
	cout<<"\nr= "<<r<<"	&q = "<<&r<<"	*q = "<<*r<<endl;
	cout<<"\ns= "<<s<<"	&q = "<<&s<<"	*q = "<<*s<<endl;
	cout<<"\nt= "<<t<<"	&q = "<<&t<<"	*q = "<<*t<<endl;
	cout<<"\nu= "<<u<<"	&q = "<<&u<<"	*q = "<<*u<<endl;
}

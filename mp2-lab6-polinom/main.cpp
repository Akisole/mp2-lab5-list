#include "Polinom.h"
using namespace std;

void main () {
	cout << "+" << endl;
	TMonom a, b, c;
	TPolinom pol, z;
	
	a.x=2; a.y=0; a.z=4; a.coeff=2;
	b.x=4; b.y=2; b.z=3; b.coeff=1;
	c.x=2; c.y=1; c.z=0; c.coeff=-3;

	pol.Push(b); 
	pol.Push(a); 
	pol.Push(c);

	cout << pol << endl;

	z=pol*c;
	cout << z << endl;


	z=z*3;
	cout << z << endl;



/*	//тест головы
	THList<int> list;
	for (int i=0; i<5; i++)
		list.Push(2*i);
	list.Push(3);
	cout << list << endl;
	cout << "+" << endl;
	cout << list.GetPoz() << endl;
	cout << list.GetSize() << endl;
*/
}
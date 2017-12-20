#include "List.h"


void main () {
	int s, a, p, i;
	cout << "All is well" << endl;
	TList<int> list;

	cout << "Size: ";
	cin >> s;
	cout << "Set " << s << " elem: ";

	for (i=0; i<s; i++) {
		cin >> a;
		list.InsLast(a);
	}
	cout << "Your list: " << endl << list << endl;
	cout << "\nYour poz in list: "  << list.GetPoz() << endl;

	cout << "Go to poz: ";
	cin >> p;
	list.SetPoz(p);
	cout << "Your poz in list: "  << list.GetPoz() << ". Elem in this poz: " << list.GetCurr() << endl;

	cout << "\nSet in first poz elem: ";
	cin >> a;
	list.InsFirst(a);
	cout << "Your list: " << endl << list << endl;
	cout << "Size: " << list.GetSize() << endl;
	cout << "Your poz in list: "  << list.GetPoz() << ". Elem in this poz: " << list.GetCurr() << endl;

	cout << "Go to poz: ";
	cin >> p;
	list.SetPoz(p);
	cout << "\nSet in this poz elem: ";
	cin >> a;
	list.InsCurr(a);
	cout << "Your list: " << endl << list << endl;
	cout << "Size: " << list.GetSize() << endl;
	cout << "Your poz in list: "  << list.GetPoz() << ". Elem in this poz: " << list.GetCurr() << endl;

}
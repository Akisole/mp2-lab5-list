#include "List.h"


void main () {
	int s, a, p, i;
	cout << "Cteate List." << endl;
	TList<int> list;

	cout << "Size: ";
	cin >> s;
	cout << "Set " << s << " elem: ";
//===== ÑÎÇÄÀÍÈÅ =====
	for (i=0; i<s; i++) {
		cin >> a;
		list.InsLast(a);
	}
	cout << "Your list: " << endl << list << endl;
	cout << "\nYour poz in list: "  << list.GetPoz() << endl;
//===== ÏÅĞÅÕÎÄ Ê ÏÎÇÈÖÈÈ =====
	cout << "Go to poz: ";
	cin >> p;
	list.SetPoz(p);
	cout << "Your poz in list: "  << list.GetPoz() << ". Elem in this poz: " << list.GetCurr() << endl;
//===== ÄÎÁÀÂËÅÍÈÅ Â ÍÀ×ÀËÎ =====
	cout << "\n---------------------------\n\nSet in first poz elem: ";
	cin >> a;
	list.InsFirst(a);
	cout << "Your list: " << endl << list << endl;
	cout << "Size: " << list.GetSize() << endl;
	cout << "Your poz in list: "  << list.GetPoz() << ". Elem in this poz: " << list.GetCurr() << endl;
//===== ÄÎÁÀÂËÅÍÈÅ Â ÊÎÍÅÖ =====
	cout << "\nSet in last: ";
	cin >> a;
	list.InsLast(a);
	cout << "Your list: " << endl << list << endl;
	cout << "Size: " << list.GetSize() << endl;
	cout << "Your poz in list: "  << list.GetPoz() << ". Elem in this poz: " << list.GetCurr() << endl;
//===== ÄÎÁÀÂËÅÍÈÅ ÏÎ ÏÎÇÈÖÈÈ =====
	cout << "\nGo to poz: ";
	cin >> p;
	list.SetPoz(p);
	cout << "Set in this poz elem: ";
	cin >> a;
	list.InsCurr(a);
	cout << "Your list: " << endl << list << endl;
	cout << "Size: " << list.GetSize() << endl;
	cout << "Your poz in list: "  << list.GetPoz() << ". Elem in this poz: " << list.GetCurr() << endl;
//===== ÓÄÀËÅÍÈÅ =====
	cout << "\n---------------------------\n\nYour list: " << endl << list << endl;
	list.DelFirst();
	cout << "Delete First elem.\nYour list: " << endl << list << endl;
	cout << "Your poz in list: "  << list.GetPoz() << ". Elem in this poz: " << list.GetCurr() << endl;

	list.DelLast();
	cout << "\nDelete Last elem.\nYour list: " << endl << list << endl;
	cout << "Your poz in list: "  << list.GetPoz() << ". Elem in this poz: " << list.GetCurr() << endl;

	cout << "\nGo to poz: ";
	cin >> p;
	list.SetPoz(p);
	cout << "Your poz in list: "  << list.GetPoz() << ". Elem in this poz: " << list.GetCurr() << endl;
	list.DelCurr();
	cout << "Delete elem.\nYour list: " << endl << list << endl;
	cout << "Size: " << list.GetSize() << endl;
	cout << "Your poz in list: "  << list.GetPoz() << ". Elem in this poz: " << list.GetCurr() << endl <<endl ;

}
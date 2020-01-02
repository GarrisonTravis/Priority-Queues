#include <iostream>
#include "UnsortedPQ.h"

using namespace std;

int main() {

	cout << "Testing UnsortedPQ: [<key, value>]" << endl;
	cout << "--------------------------------" << endl;
	UnsortedPQ <char> u;
	pair<int, char> p;
	u.push(1, 'A');
	u.push(2, 'B');
	u.push(3, 'C');
	u.push(2, 'D');
	u.push(0, 'E');
	u.print();
	
	//Popping every entry in the UnsortedPQ to show that the entries will be sorted by their priority/keys
	cout << "\nPopping every entry in the UnsortedPQ ..." << endl <<endl ;
	cout << "By pushing and then popping every entry, the resulting output is sorted by the keys: ";
	int size = u.size();
	for (int i = 0; i < size; i++) {
		p = u.top();
		if(i == size - 1)
			cout << "<" << p.first << ", " << p.second << ">";
		else
			cout << "<" << p.first << ", " << p.second << ">" << " ";
		u.pop();
	}
	cout << endl;
}

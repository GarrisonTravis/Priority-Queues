#include <iostream>
#include <exception>
#include "UnsortedPQ.h"
#include "SortedPQ.h"
#include "HeapPQ.h"

using namespace std;

int main() {

	cout << "Testing UnsortedPQ: [<key, value>]" << endl;
	cout << "--------------------------------" << endl << endl;
	UnsortedPQ <char> u;
	pair<int, char> p;

	cout << "Pushing 5 entries ..." << endl << endl;
	u.push(1, 'A');
	u.push(2, 'B');
	u.push(3, 'C');
	u.push(2, 'D');
	u.push(0, 'E');
	u.print();
	
	//Popping every entry in the UnsortedPQ to show that the entries will be sorted by their priority/keys
	cout << "\nPopping every entry in the UnsortedPQ ..." << endl <<endl ;
	cout << "The resulting output is sorted by the keys from highest to lowest: ";
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

	cout << "\nTesting SortedPQ: [<key, value>]" << endl;
	cout << "--------------------------------" << endl;
	SortedPQ <char> s;

	cout << "Pushing 5 entries ..." << endl << endl;
	s.push(1, 'A');
	s.push(2, 'B');
	s.push(3, 'C');
	s.push(2, 'D');
	s.push(0, 'E');
	s.print();

	//Popping every entry in the SortedPQ to show that the entries will be sorted by their priority/keys
	cout << "\nPopping every entry in the SortedPQ ..." << endl << endl;
	cout << "The resulting output is sorted by the keys from highest to lowest: ";
	size = s.size();
	for (int i = 0; i < size; i++) {
		p = s.top();
		if (i == size - 1)
			cout << "<" << p.first << ", " << p.second << ">";
		else
			cout << "<" << p.first << ", " << p.second << ">" << " ";
		s.pop();
	}
	cout << endl;

	cout << "\nTesting HeapPQ: [<key, value>]" << endl;
	cout << "--------------------------------" << endl;
	HeapPQ<char> h;

	cout << "Pushing 9 entries ..." << endl << endl;
	h.push(1, 'A');
	h.push(2, 'B');
	h.push(3, 'C');
	h.push(2, 'D');
	h.push(0, 'E');
	h.push(1, 'F');
	h.push(4, 'G');
	h.push(5, 'H');
	h.push(3, 'I');
	h.print();

	//Popping every entry in the HeapPQ to show that the entries will be sorted by their priority/keys
	cout << "\nPopping every entry in the HeapPQ ..." << endl << endl;
	cout << "The resulting output is sorted by the keys from highest to lowest: ";
	size = h.size();
	for (int i = 0; i < size; i++) {
		p = h.top();
		if (i == size - 1)
			cout << "<" << p.first << ", " << p.second << ">";
		else
			cout << "<" << p.first << ", " << p.second << ">" << " ";
		h.pop();
	}
	cout << endl;
	
}

#include <iostream>
#include "UnsortedPQ.h"

using namespace std;

int main() {

	UnsortedPQ <char> u;
	pair<int, char> p;
	u.push(1, 'A');
	u.push(2, 'B');
	u.push(3, 'C');
	u.push(2, 'D');
	u.print();
	p = u.top();
	cout << "Popped: " << "<" << p.first << ", " << p.second << ">" << endl;
	u.pop();
	
	u.print();
}

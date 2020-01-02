#ifndef HEAPPQ_H
#define HEAPPQ_H

#include <vector>
#include <utility>
#include <stdexcept>

using namespace std;

template <class Type>
class HeapPQ {
private:
	vector<pair<int, Type>> hPQ;
	int heapSize;
public:
	HeapPQ() : heapSize(0) {}

	~HeapPQ() {
		hPQ.clear();
	}

    //Returns true if PQ is empty, else return false
    bool empty() {
        if (heapSize == 0)
            return true;
        else
            return false;
    }

    //Returns the size of the PQ
    int size() {
        return heapSize;
    }

	//Returns the parent key for the given index
	pair<int, Type> getParent(int index) {
		return hPQ.at((index - 1) / 2);
	}

	//Returns the index of the parent entry
	int getParentIndex(int index) {
		return (index - 1) / 2;
	}

	//Sets the parent node's data value
	void setParent(int priority, Type val, int index) {
		hPQ[(index - 1) / 2].first = priority;
		hPQ[(index - 1) / 2].second = val;
	}

	//Returns the data value of left node
	Type getLeft(int index) {
		return hPQ[(2 * index) + 1];
	}

	//Returns the index of the left child
	int getLeftIndex(int index) {
		return (2 * index) + 1;
	}

	//Returns the index of the right child
	int getRightIndex(int index) {
		return (2 * index) + 2;
	}

	//Returns the data value of right node
	Type getRight(int index) {
		return hPQ[(2 * index) + 2];
	}

    //Pushes a <priority, value> pair onto the heap PQ
    //Post: The heap PQ will contain the new pair at the correct spot according to its key
    void push(int priority, Type val) {
		heapSize++;
		int index = heapSize - 1;
		hPQ.push_back(make_pair(priority, val));	//add new entry to the heap

		//While loop to rearrange the heap to satisfy max heap requirements
		while (getParent(index).first < hPQ.at(index).first && index != 0) {

			//Swap parent entry with current index entry
			hPQ.at(index).first = getParent(index).first;
			hPQ.at(index).second = getParent(index).second;
			setParent(priority, val, index);

			index = getParentIndex(index);		//new index
		}
    }

	//Outputs the current heap PQ to the screen
    //Includes the key and value
	void print() {
		cout << "HeapPQ = [";
		for (int i = 0; i < size(); i++) {
			if (i == size() - 1)
				cout << "<" << hPQ[i].first << ", " << hPQ[i].second << ">";
			else
				cout << "<" << hPQ[i].first << ", " << hPQ[i].second << "> ";
		}
		cout << "]";
		cout << endl;
	}
};

#endif

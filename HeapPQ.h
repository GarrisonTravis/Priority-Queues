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
	pair<int, Type> getLeft(int index) {
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
	pair<int, Type> getRight(int index) {
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

	//Pops the <priority, value> pair with the highest priority
	//Post: The heap PQ will no longer contain the pair with highest priority
	pair<int, Type> pop() {
		if (empty())
			throw runtime_error("The Queue is Empty. Max Priority Doesn't Exist");

		//Condition if heap has a size of 1
		if (heapSize == 1) {
			pair<int, Type> temp = hPQ.at(0);
			heapSize--;
			hPQ.pop_back();
			return temp;
		}

		//Swapping the root node with the last node 
		pair<int, Type> temp = hPQ.at(0);
		hPQ[0].first = hPQ.at(heapSize - 1).first;
		hPQ[0].second = hPQ.at(heapSize - 1).second;
		hPQ[heapSize - 1] = temp;

		//Extract the max value
		pair<int, Type> max = hPQ.at(heapSize - 1);
		hPQ.pop_back();
		heapSize--;

		//Reheaps the heap to satisfy the conditions of a max heap
		int index = 0;
		int currentPosition = 0;
		while (getLeftIndex(index) < heapSize) {
			//Checks to see if there is a right node and if greater than the left node
			if (getRightIndex(index) < heapSize && getRight(index).first > getLeft(index).first) {
				currentPosition = getRightIndex(index);
			}
			//Checks to see if there is a right node and if it is equal to the left node
			else if (getRightIndex(index) < heapSize && getRight(index).first == getLeft(index).first) {
				//If right and left are equal, look at their val, pick one with lowest value
				//This is personal design decision. I wanted the lesser value to appear first if left and right node are equal keys
				if (getRight(index).second < getLeft(index).second) 
					currentPosition = getRightIndex(index);
				else
					currentPosition = getLeftIndex(index);
			}
			else {
				currentPosition = getLeftIndex(index);
			}

			//Checks if current node is greater than its parent node
			//If true, then swap the nodes
			if (hPQ.at(currentPosition).first > hPQ.at(index).first) {
				temp = hPQ.at(index);
				hPQ[index] = hPQ.at(currentPosition);
				hPQ[currentPosition] = temp;

				index = currentPosition;
			}
			else
				break;
		}

		return max;
	}

	//Returns the <priority, value> pair with the highest priority
	//Post: The heap PQ is the same as before
	pair<int, Type> top() {
		//Throw exception if the PQ is empty
		if (empty())
			throw runtime_error("The Queue is Empty. Max Priority Doesn't Exist");

		return hPQ.at(0);
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

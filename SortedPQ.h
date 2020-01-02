#ifndef SORTEDPQ_H
#define SORTEDPQ_H

#include <vector>
#include <utility>
#include <stdexcept>

using namespace std;

template <class Type>
class SortedPQ {
private:
	vector<pair<int, Type>> sPQ;
public:
	SortedPQ() {}

	~SortedPQ() {
		sPQ.clear();
	}

    //Returns true if PQ is empty, else return false
    bool empty() {
        if (sPQ.size() == 0)
            return true;
        else
            return false;
    }

    //Returns the size of the PQ
    int size() {
        return sPQ.size();
    }

    //Pushes a <priority, value> pair onto the sorted PQ
    //Post: The sorted PQ will contain the new pair at the correct spot according to its key
    void push(int priority, Type val) {
        
        typename vector<pair<int, Type>>::iterator itr = sPQ.begin();

        while (itr != sPQ.end() && itr->first >= priority) {
            itr++;
        }
        sPQ.insert(itr, make_pair(priority, val));
    }

    //Pops the <priority, value> pair with the highest priority
    //Post: The sorted PQ will no longer contain the pair with highest priority
    pair<int, Type> pop() {
        //Throw exception if the PQ is empty
        if (empty())
            throw runtime_error("The Queue is Empty. Max Priority Doesn't Exist");

        pair<int, Type> temp = *sPQ.begin();

        sPQ.erase(sPQ.begin());

        return temp;
    }

    //Returns the <priority, value> pair with the highest priority
    //Post: The sorted PQ is the same as before
    pair<int, Type> top() {
        //Throw exception if the PQ is empty
        if (empty())
            throw runtime_error("The Queue is Empty. Max Priority Doesn't Exist");

        return *sPQ.begin();
    }

    //Outputs the current unsorted PQ to the screen
    //Includes the key and value
    void print() {
        cout << "SortedPQ = [";
        for (int i = 0; i < sPQ.size(); i++) {
            if (i == size() - 1)
                cout << "<" << sPQ[i].first << ", " << sPQ[i].second << ">";
            else
                cout << "<" << sPQ[i].first << ", " << sPQ[i].second << "> ";
        }
        cout << "]";
        cout << endl;
    }
};

#endif

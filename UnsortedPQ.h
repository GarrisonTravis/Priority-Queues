//UnsortedPQ.h
//Garrison Travis
#ifndef UNSORTEDPQ_H
#define UNSORTEDPQ_H
#include <vector>
#include <utility>
#include <stdexcept>

using namespace std;

//Unsorted Priority Queue
template <class Type>
class UnsortedPQ {
private:
    vector<pair<int, Type>> uPQ;
public:
    UnsortedPQ() {}

    ~UnsortedPQ() {
        uPQ.clear();
    }
    
    //Returns true if PQ is empty, else return false
    bool empty() {
        if (uPQ.size() == 0)
            return true;
        else
            return false;
    }

    //Returns the size of the PQ
    int size() {
        return uPQ.size();
    }

    //Pushes a <priority, value> pair onto the unsorted PQ
    //Post: The unsorted PQ will contain the new pair at the end of the vector
    void push(int priority, Type val) {
        uPQ.push_back(make_pair(priority, val));
    }

    //Pops the <priority, value> pair with the highest priority
    //Post: The unsorted PQ will no longer contain the pair with highest priority
    pair<int, Type> pop() {
        //Throw exception if the PQ is empty
        if (empty())
            throw runtime_error("The Queue is Empty. Max Priority Doesn't Exist");

       typename vector<pair<int, Type>>::iterator itr = uPQ.begin();
       typename vector<pair<int, Type>>::iterator maxIndex = uPQ.begin();
       pair<int, Type> max = uPQ[0];

       //Find the max priority pair in the PQ
       while (itr != uPQ.end()) {
           if (itr->first > max.first) {
               max = *itr;
               maxIndex = itr;
           }
           else {
               itr++;
           }
       }
       uPQ.erase(maxIndex);     //Erase max priority pair 

       return max;       
    }

    //Returns the <priority, value> pair with the highest priority
    //Post: The unsorted PQ is the same as before
    pair<int, Type> top() {
        //Throw exception if the PQ is empty
        if (empty())
            throw runtime_error("The Queue is Empty. Max Priority Doesn't Exist");

        typename vector<pair<int, Type>>::iterator itr = uPQ.begin();
        pair<int, Type> max = uPQ[0];

        while (itr != uPQ.end()) {
            if (itr->first > max.first) {
                max = *itr;
            }
            else {
                itr++;
            }
        }

        return max;
    }

    //Outputs the current unsorted PQ to the screen
    //Includes the key and value
    void print() {
        cout << "UnsortedPQ = [";
        for (int i = 0; i < uPQ.size(); i++) {
            if(i == size() - 1)
                cout << "<" << uPQ[i].first << ", " << uPQ[i].second << ">";
            else
                cout << "<" << uPQ[i].first << ", " << uPQ[i].second << "> ";
        }
        cout << "]";
        cout << endl;
    }

};

#endif

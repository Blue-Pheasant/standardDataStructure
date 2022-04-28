#include <iostream>
#include "singleLinkedList.h"
#include "stack.h"
#include "queue.h"
#include <list>
using namespace std;

int main() {
    LinkedList<int> myList;
    for(int i = 0; i < 10; i++) {
        myList.push_back(i);
    }

    for(auto x : myList) {
        cout << x << " ";
    }

}
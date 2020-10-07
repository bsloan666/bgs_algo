#include "bgs_max_heap.h"
#include "bgs_min_heap.h"
#include <iostream>

using namespace std;

int main(){
    MinHeap<int> heap = MinHeap<int>();
    cout << "MinHeap:" << endl; 
    int i;
    for(i = 1; i < 14; i ++){
        heap.insert(i*2);
    }

    heap.dump();
    cout << endl;

    int lowest = heap.extract_min();

    cout << "extracted lowest: " << lowest << endl;

    heap.dump();

    heap.insert(9);

    cout << endl << "inserted 9 " << endl;

    heap.dump();

    MaxHeap<int> mheap = MaxHeap<int>();
    cout << "MaxHeap:" << endl; 
    for(i = 1; i < 14; i ++){
        mheap.insert(i*2);
    }

    mheap.dump();
    cout << endl;

    int highest = mheap.extract_max();

    cout << "extracted highest: " << highest << endl;

    mheap.dump();

    mheap.insert(19);

    cout << endl << "inserted 19 " << endl;

    mheap.dump();
}

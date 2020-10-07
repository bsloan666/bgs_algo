#include "bgs_heap_2.h"
#include <iostream>

using namespace std;

int main(){
    BGSHeap<int> heap = BGSHeap<int>();
    
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
}

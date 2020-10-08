#include "bgs_max_heap.h"
#include "bgs_min_heap.h"
#include "bgs_trie.h"
#include <iostream>

using namespace std;

void test_minheap(){
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
}
void test_maxheap(){
    int i;
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
void test_trie(){
    Trie dict_trie;
    int i;
    string words[6] = {"abacus", "above", "about", "absolution", "absolutely", "abdominal"}; 
    for(size_t i = 0; i < 6; i++){
        dict_trie.insert(words[i], true);
    }
    vector<string> results;
    vector<char> prefix;
    prefix.push_back('a');
    prefix.push_back('b');
    prefix.push_back('s');
    dict_trie.keys_with_prefix(prefix, results );
    for(i=0; i < results.size(); i++){
        cout << results[i] << endl;
    }
}


int main(){
    test_minheap();
    test_maxheap();
    test_trie();

}

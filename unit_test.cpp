#include "bgs_max_heap.h"
#include "bgs_min_heap.h"
#include "bgs_trie.h"
#include "bgs_mergesort.h"
#include "bgs_quicksort.h"
#include "bgs_exp_hashmap.h"
#include "bgs_sqrt.h"
#include <iostream>

using namespace std;

void test_minheap(){
    MinHeap<int> heap = MinHeap<int>();
    cout << "MinHeap:" << endl; 
    int i;
    for(i = 1; i < 14; i++){
        heap.insert(i*2);
    }
    heap.dump();
    cout << endl;

    int lowest = heap.extract_min();

    cout << "    extracted lowest: " << lowest << endl;
    heap.dump();

    heap.insert(9);

    cout << endl << "    inserted 9 " << endl;
    heap.dump();
    cout << endl;
}
void test_maxheap(){
    int i;
    MaxHeap<int> mheap = MaxHeap<int>();
    cout << "MaxHeap:" << endl; 
    for(i = 1; i < 14; i++){
        mheap.insert(i*2);
    }

    mheap.dump();
    cout << endl;

    int highest = mheap.extract_max();
    cout << "    extracted highest: " << highest << endl;

    mheap.dump();
    mheap.insert(19);

    cout << endl << "    inserted 19 " << endl;
    mheap.dump();
    cout << endl;
}
void test_trie(){
    Trie dict_trie;
    int i;
    cout << "Trie:" << endl; 
    string words[] = {
         "abacus", "above", "about", "abstinence", 
         "absolution", "absolutely", "abdominal",
         "abelian", "able", "absorption", "absent"
    }; 
    for(size_t i = 0; i < 11; i++){
        dict_trie.insert(words[i], true);
    }
    vector<string> results;
    vector<char> prefix;
    prefix.push_back('a');
    prefix.push_back('b');
    prefix.push_back('s');
    dict_trie.keys_with_prefix(prefix, results );
    for(i=0; i < results.size(); i++){
        cout << "    " << results[i] << endl;
    }
    cout << endl;
}
void test_merge_sort(){
    vector<int> unsorted;
    cout << "MergeSort:" << endl; 
    int tmp[] = {14, 1, 15, 23, 3, 2, 16, 11, 9};
    for(int i = 0; i < 9; i++){
        unsorted.push_back(tmp[i]);
        cout << "    " << tmp[i] << " "; 
    }
    cout << endl;
    merge_sort(unsorted);
    for(int i = 0; i < 9; i++){
        cout << "    " << unsorted[i] << " "; 
    }
    cout << endl;

}

void test_quicksort(){
    vector<int> unsorted;
    cout << "QuickSort:" << endl; 
    int tmp[] = {14, 1, 15, 23, 3, 2, 16, 11, 9};
    for(int i = 0; i < 9; i++){
        unsorted.push_back(tmp[i]);
        cout << "    " << tmp[i] << " ";
    }
    cout << endl;
    quicksort(unsorted, 0, unsorted.size()-1);
    for(int i = 0; i < 9; i++){
        cout << "   " << unsorted[i] << " "; 
    }
    cout << endl;

}
void test_hashmap() {
    cout << "Expandable HashMap:" << endl; 
    ExpandableHashMap<string, int> hmap = ExpandableHashMap<string, int>(0.5);
    hmap.associate("twelve", 12);
    hmap.associate("eleven", 11);
    hmap.associate("eight", 8);
    hmap.associate("nine", 9);
    hmap.associate("twenty", 20);
    hmap.associate("twentyone", 21);
    hmap.associate("five", 5);
    hmap.associate("four", 4);
    hmap.associate("thirty", 30);
    hmap.associate("thirtyfour", 34);
    hmap.associate("six", 6);

    cout << "    " <<hmap.size() << endl;
    const int *result = hmap.find("nine");

    cout << "    "  << *(result) << " = nine" << endl;
    cout << endl;
}
void test_sqrt() {
    cout << "Square Root:" << endl; 
    double a(9.0), b(12), c(450), d(2938.576), e(97867453.345);

    double aa = bgs_sqrt(a);
    double bb = bgs_sqrt(b);
    double cc = bgs_sqrt(c);
    double dd = bgs_sqrt(d);
    double ee = bgs_sqrt(e);
    cout << endl;

    cout << "    bgs_sqrt(" << a << ")= " << aa << "  sqrt(" << a << ")= " << sqrt(a) <<endl;
    cout << "    bgs_sqrt(" << b << ")= " << bb << "  sqrt(" << b << ")= " << sqrt(b) <<endl;
    cout << "    bgs_sqrt(" << c << ")= " << cc << "  sqrt(" << c << ")= " << sqrt(c) <<endl;
    cout << "    bgs_sqrt(" << d << ")= " << dd << "  sqrt(" << d << ")= " << sqrt(d) <<endl;
    cout << "    bgs_sqrt(" << e << ")= " << ee << "  sqrt(" << e << ")= " << sqrt(e) <<endl;
    cout << endl;
}

int main(){
    test_minheap(); 
    test_maxheap();
    test_trie();
    test_merge_sort();
    test_quicksort();
    test_hashmap();
    test_sqrt();

}

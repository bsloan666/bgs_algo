#include <vector>
#include <iostream>

template <class T>
void _swap(vector<T> &A, size_t i, size_t j){
    T tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

template <class T>
size_t _partition(vector<T> &A, size_t lo, size_t hi) {
    T pivot = A[(hi+lo)/2];
    size_t i = lo - 1;
    size_t j = hi + 1;
    while(1) {
        do { 
            i++;
        } while(A[i] < pivot);
        do {
            j--;
        } while(A[j] > pivot);
        if( i >= j) {
            return j;
        }
        _swap(A, i, j);
    }

}

template <class T>
void quicksort(vector<T> &A, size_t lo, size_t hi){
    if(lo < hi) {
        size_t p = _partition(A, lo, hi);
        quicksort(A, lo, p);
        quicksort(A, p+1, hi);
    }
}

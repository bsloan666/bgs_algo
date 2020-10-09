#include <vector>
#include <iostream>
using namespace std;

// Thanks, Wikipedia!

template <class T>
void _merge(vector<T> &A, size_t start, size_t mid, size_t end, vector<T> &B){
    size_t i = start, j = mid;
    for(size_t k = start; k < end; k++){
        if(i< mid && (j>=end || A[i] < A[j])){
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
    }
}

template <class T>
void _split_merge(vector<T> &B, size_t start, size_t end, vector<T> &A) {
    if(end - start <= 1) {
        return;
    }
    size_t mid = (start + end)/2;
    _split_merge(A, start, mid, B);
    _split_merge(A, mid, end, B);
    _merge(B, start, mid, end, A);
}

template <class T>
void merge_sort(vector<T> &tosort) {
    size_t n = tosort.size();
    vector<T> work;
    for(int i = 0; i< n; i++)
        work.push_back(tosort[i]);
    _split_merge(work, 0, n, tosort);
}

#include <vector>
#include <iostream>

using namespace std;

template <class T>
class MinHeap {
    public:
    MinHeap<T>() {}

    size_t size() {
        return m_array.size();
    }
    void insert(T val) {
       m_array.push_back(val);
       if(size() == 1){
           return;
       }
       sift_up();
    }

    T extract_min() {
       T result = m_array[0];
       swap(0, m_array.size()-1);
       m_array.pop_back();
       sift_down();
       return result;
    }

    void dump(){
        size_t i, j=2, k=0;
        size_t d = depth()*2;
        for(int m = 0; m < d; m++)cout << " ";
        for(i = 0; i < size(); i++){
            cout << m_array[i] << " ";
            if(i == k){
                d-=2;
                cout << endl;
                for(int m = 0; m < d; m++)cout << " ";
                k += j;
                j *= 2;
            }
        }
        cout << endl;
    }
    
    private:
    size_t left(size_t i) {
        return 2 * i + 1;
    }

    size_t right(size_t i) {
        return left(i) + 1;
    }
    size_t parent(size_t i){
        int result = (i - 1)/2;
        if(result < 0) {
            result = 0;
        }
        return result;
    }

    void swap(size_t i, size_t j){
        T tmp = m_array[i];
        m_array[i] = m_array[j];
        m_array[j] = tmp;
    }
  
    void sift_up() {
        size_t sz = size();
        size_t i = sz-1;
        T newval = m_array[i];
        while(newval < m_array[parent(i)] && i > 0){
            swap(i, parent(i));
            i = parent(i);
        }
    }
    void sift_down(){
        size_t i = 0;
        size_t sz = size();
        T newval = m_array[i];
        while(i < sz){
            if( left(i) < sz){
                if( right(i) < sz){
                    if( newval < m_array[left(i)] && newval < m_array[right(i)]){
                        return;
                    }
                    if(m_array[left(i)] < m_array[right(i)]) {
                        swap(i, left(i));
                        i = left(i);
                    } else {
                        swap(i, right(i));
                        i = right(i);
                    }
                } else {
                    if( newval < m_array[left(i)]){
                        return;
                    }
                    swap(i, left(i));
                    i = left(i);
                }
            }
            else {
                return;
            }
        }
    }

    size_t depth() {
        size_t result = 1;
        size_t i = result;
        while(i < size()){
           i*=2;
           result++;
        }
        return result;
    }
    
    vector<T> m_array;
};

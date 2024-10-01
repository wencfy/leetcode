#include "iostream"
#include "vector"
using namespace std;

class CustomStack {
public:
    vector<int> container;
    int maxSize;
    int idx;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        container = vector<int>(maxSize, 0);
        idx = -1;
    }
    
    void push(int x) {
        if (idx < maxSize - 1) {
            container[++idx] = x;
        }
    }
    
    int pop() {
        if (idx == -1) {
            return -1;
        } else {
            return container[idx--];
        }
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k && i <= idx; i++) {
            container[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
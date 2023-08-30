#include "iostream"
using namespace std;

class MyStack {
    int arr[100];
    int n = 0;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        arr[n++] = x;
    }
    
    int pop() {
        n--;
        return arr[n];
    }
    
    int top() {
        return arr[n - 1];
    }
    
    bool empty() {
        return n == 0;
    }
};
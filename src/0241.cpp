#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ret;

        cout << ret.size() << endl;
        
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '+') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int a: left) {
                    for (int b: right) {
                        ret.push_back(a + b);
                    }
                }
            } else if (expression[i] == '-') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int a: left) {
                    for (int b: right) {
                        ret.push_back(a - b);
                    }
                }
            } else if (expression[i] == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int a: left) {
                    for (int b: right) {
                        ret.push_back(a * b);
                    }
                }
            }
        }

        if (ret.size() == 0) {
            ret.push_back(stoi(expression));
        }
        
        return ret;
    }
};
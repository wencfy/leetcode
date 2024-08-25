#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0;
        int denominator = 2520;

        if (expression[0] != '-' && expression[0] != '+') {
            expression = '+' + expression;
        }
        stringstream ss(expression);
        char op;
        char del;
        int nu;
        int de;
        while (ss >> op) {
            if (op == '+') {
                ss >> nu >> del >> de;
                nu *= denominator / de;
                numerator += nu;
            } else if (op == '-') {
                ss >> nu >> del >> de;
                nu *= denominator / de;
                numerator -= nu;
            }
        }

        for (int i = 10; i >= 1; i--) {
            if (numerator % i == 0 && denominator % i == 0) {
                numerator /= i;
                denominator /= i;
            }
        }

        return to_string(numerator) + "/" + to_string(denominator ? denominator : 1);
    }
};
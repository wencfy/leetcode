/**
 * New 21 Game
 * 
 * Alice plays the following game, loosely based on the card game "21".
 * 
 */

#include "iostream"
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        double probs[n + 1];
        int i;
        for (i = 0; i <= n - k && i <= n; i++) {
            probs[i] = 1;
        }
        
        if (i <= n) {
            probs[i] = (i + 0.) / maxPts;
            i++;
        }
        
        for (; i <= maxPts && i <= n; i++) {
            probs[i] = probs[i - 1] * (maxPts + 1) / maxPts;
        }
        for (; i <= n; i++) {
            probs[i] = probs[i - 1] * (maxPts + 1) / maxPts - probs[i - maxPts - 1] / maxPts;
        }

        // for (int i = 0; i <= n; i++) {
        //     cout << probs[i] << " ";
        // }
        // cout << endl;
        
        return probs[n] < 1.0 ? probs[n] : 1.0;
    }
};

int main() {
    cout << (new Solution()) ->new21Game(21, 17, 10) << endl;
}
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret = vector<int>(n + 1);
        
        for (int i = 0; pow(2, i) <= n; i++) {
            for (int j = pow(2, i); j <= min((int)pow(2, i + 1) - 1, n); j++) {
                ret[j] = ret[j - pow(2, i)] + 1;
            }
        }

        return ret;
    }
};

int main() {
    auto v = (new Solution())->countBits(5);
    for (int i: v) {
        cout << i << " ";
    }
    cout << endl;
}
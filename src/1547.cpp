/**
 * Minimum Cost to Cut a Stick
 * 
 * Given a wooden stick of length n units. The stick is labelled from 0 to n.
 * For example, a stick of length 6 is labelled as follows:
 * 
 * Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
 * 
 * You should perform the cuts in order, you can change the order of the cuts as you wish.
 * 
 * The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts.
 * When you cut a stick, it will be split into two smaller sticks
 * (i.e. the sum of their lengths is the length of the stick before the cut).
 * Please refer to the first example for a better explanation.
 * 
 * Return the minimum total cost of the cuts.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size() + 2, vector<int>(cuts.size() + 2, 0));

        for (int i = 2; i < cuts.size(); i++) {
            for (int s = 0; s + i < cuts.size(); s++) {
                int minC = INT_MAX;
                for (int split = s + 1; split < s + i; split++) {
                    int tmp = cuts[s + i] - cuts[s] + dp[s][split] + dp[split][s + i];
                    if (minC > tmp) {
                        minC = tmp;
                    }
                }
                dp[s][s + i] = minC;
            }
        }

        return dp[0][cuts.size() - 1];
    }
};

int main() {
    vector<int> cuts = {1,3,4,5};
    cout << (new Solution()) ->minCost(7, cuts) << endl;
}
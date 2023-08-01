/**
 * Combinations
 * 
 * Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
 * 
 * You may return the answer in any order.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
    vector<vector<int>> ret = vector<vector<int>>();
    int num = 0;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur = {};
        dfs(1, cur, n, k);

        return ret;
    }

    void dfs(int c, vector<int> &cur, int n, int k) {
        if (num == k) {
            ret.push_back(cur);
            return ;
        }

        if (c > n) {
            return ;
        }

        cur.push_back(c);
        num++;
        dfs(c + 1, cur, n, k);
        cur.pop_back();
        num--;

        dfs(c + 1, cur, n, k);
        return ;
    }
};

int main() {
    auto ret = (new Solution())->combine(20, 16);
    cout << "-------------" << endl;
    for (auto l: ret) {
        for (int i: l) {
            cout << i << " ";
        }
        cout << endl;
    }
}
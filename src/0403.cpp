#include "iostream"
#include "vector"
#include "map"
using namespace std;

class Solution {
    int n;
    vector<int> stones;
    map<pair<int, int>, bool> mp;
public:
    bool canCross(vector<int>& stones) {
        n = stones.size();
        this->stones = stones;

        return dfs(0, 0);
    }

    bool dfs(int cur, int steps) {
        if (cur == n - 1) {
            return true;
        }

        if (mp.find({cur, steps}) != mp.end()) {
            return mp.at({cur, steps});
        }

        int i = cur + 1;
        while (i < n && stones[i] - stones[cur] < steps - 1) {
            i++;
        }

        bool ret = false;
        for (; i < n && stones[i] - stones[cur] <= steps + 1; i++) {
            ret = ret || dfs(i, stones[i] - stones[cur]);
        }

        mp.insert({{cur, steps}, ret});
        return ret;
    }
};

int main() {
    vector<int> vec = {0,1,3,5,6,8,12,17};
    cout << (new Solution())->canCross(vec) << endl;
}
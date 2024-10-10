#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int mx;
    vector<int> vis;
    int maxJumps(vector<int>& arr, int d) {
        mx = arr.size() - 1;
        vis = vector<int>(arr.size(), -1);

        int ret = 0;
        for (int i = 0; i <= mx; i++) {
            ret = max(ret, dfs(i, d, arr));
        }
        
        return ret + 1;
    }

    int dfs(int x, int d, vector<int>& arr) {
        if (vis[x] != -1) {
            return vis[x];
        }

        int tmp = 0;
        for (int i = x + 1; i <= x + d && i <= mx; i++) {
            if (arr[x] <= arr[i]) {
                break;
            } else {
                tmp = max(tmp, 1 + dfs(i, d, arr));
            }
        }

        for (int i = x - 1; i >= x - d && i >= 0; i--) {
            if (arr[x] <= arr[i]) {
                break;
            } else {
                tmp = max(tmp, 1 + dfs(i, d, arr));
            }
        }

        vis[x] = tmp;
        return vis[x];
    }
};
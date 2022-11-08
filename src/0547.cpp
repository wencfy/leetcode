/**
 * Number of Provinces
 * 
 * There are n cities. Some of them are connected, while some are not.
 * If city a is connected directly with city b, and city b is
 * connected directly with city c, then city a is connected indirectly
 * with city c.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> isConnected;
    vector<int> isVisited;

    void init(vector<vector<int>>& isConnected) {
        this ->isConnected = isConnected;
        this ->isVisited = vector<int>(isConnected.size());
    }

    void dfs(int x) {
        if (isVisited[x]) {
            return ;
        }
        isVisited[x] = 1;
        for (int i = 0; i < isConnected[x].size(); i++) {
            if (isConnected[x][i]) {
                dfs(i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        init(isConnected);
        int count = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!isVisited[i]) {
                count++;
                dfs(i);
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> isConnected = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
    cout << (new Solution()) ->findCircleNum(isConnected) << endl;
}
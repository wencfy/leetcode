#include "iostream"
using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> graph = {
            {4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9},
            {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}
        };
        const long long int mod = 1e9 + 7;
        
        vector<long long int> prev(10, 1);
        vector<long long int> cur(10, 0);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                cur[j] = 0;
                for (int k = 0; k < graph[j].size(); k++) {
                    cur[j] += prev[graph[j][k]];
                }
                cur[j] %= mod;
            }
            cur.swap(prev);
        }

        long long int s = 0;
        for (long long i: prev) {
            s = (s + i) % mod;
        }
        return s;
    }
};
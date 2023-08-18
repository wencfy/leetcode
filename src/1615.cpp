/**
 * Maximal Network Rank
 * 
 * There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
 * 
 * The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.
 * The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
 * Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
 */

#include "iostream"
#include "vector"
#include "set"
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> in = vector<int>(n, 0);
        set<pair<int, int>> s;
        for (auto road: roads) {
            in[road[0]]++;
            in[road[1]]++;
            if (road[0] < road[1]) {
                s.insert({road[0], road[1]});
            } else {
                s.insert({road[1], road[0]});
            }
        }

        int maxRank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = in[i] + in[j] - 1;
                if (!s.count({i, j})) {
                    rank += 1;
                }
                if (maxRank < rank) {
                    maxRank = rank;
                }
            }
        }
        return maxRank;
    }
};
/**
 * Equal Row and Column Pairs
 * 
 * Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.
 * A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).
 */

#include "iostream"
#include "vector"
#include "string"
#include "map"
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string, int> mp;
        
        for (vector<int> numVec: grid) {
            mp[toString(numVec)]++;
        }

        int sumPair = 0;
        for (int i = 0; i < grid.size(); i++) {
            string s = "";
            for (int j = 0; j < grid.size(); j++) {
                s += to_string(grid[j][i]) + " ";
            }
            sumPair += mp[s];
        }
        return sumPair;
    }

    string toString(vector<int> &numVec) {
        string ret = "";
        for (int num: numVec) {
            ret += to_string(num) + " ";
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> grid = {{3,1,2,2}, {1,4,4,5}, {2,4,2,2}, {2,4,2,2}};
    cout << (new Solution()) ->equalPairs(grid) << endl;
}
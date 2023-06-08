/**
 * Count Negative Numbers in a Sorted Matrix
 * 
 * Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int j = grid.front().size() - 1;
        int cnt = 0;
        
        int i = 0;
        while (i < grid.size()) {
            while (j >= 0) {
                if (grid[i][j] < 0) {
                    j--;
                } else {
                    break;
                }
            }
            cout << cnt << endl;
            cnt += grid.front().size() - 1 - j;
            i++;
        }
        return cnt;
    }
};
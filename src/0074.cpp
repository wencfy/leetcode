/**
 * Select a 2D Matrix
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() * matrix[0].size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (getVal(matrix, mid) == target) {
                return true;
            } else if (getVal(matrix, mid) < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }

    int getVal(vector<vector<int>>& matrix, int index) {
        int width = matrix[0].size();
        int indexX = index / width;
        int indexY = index % width;
        return matrix[indexX][indexY];
    }
};

int main() {
    vector<vector<int>> matrix = {
        { 1, 3, 5, 7 },
        { 10, 11, 16, 20 },
        { 23, 30, 24, 60 }
    };
    cout << (new Solution()) ->searchMatrix(matrix, 61) << endl;
    return 0;
}

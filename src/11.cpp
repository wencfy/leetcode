/**
 * Container With Most Water
 */

#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int maxArea = -1;
        while (low < high) {
            int content;
            if (height[low] > height[high]) {
                content = (high - low) * height[high];
                high--;
            } else {
                content = (high - low) * height[low];
                low++;
            }
            if (content > maxArea) {
                maxArea = content;
            }
        }
        return maxArea;
    }
};

int main() {
    vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << (new Solution()) ->maxArea(height) << endl;
}
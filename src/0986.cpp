/**
 * Interval List Intersections
 */

#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            int start = max(firstList[i][0], secondList[j][0]);
            int end;
            if (firstList[i][1] > secondList[j][1]) {
                end = secondList[j][1];
                j++;
            } else {
                end = firstList[i][1];
                i++;
            }
            if (start <= end) {
                res.push_back({ start, end });
            }
        }
        return res;
    }
};

void printList(vector<vector<int>> res) {
    for (vector<int> v: res) {
        for (int i: v) {
            cout << i << ", ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> firstList = { {0, 2}, {5, 10}, {13, 23}, {24, 25} };
    vector<vector<int>> secondList = { {1, 5}, {8, 12}, {15, 24}, {25, 26} };
    vector<vector<int>> res = (new Solution()) ->intervalIntersection(firstList, secondList);
    printList(res);
}
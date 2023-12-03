#include "iostream"
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ret = 0;
        vector<int> lastPoint = points[0];
        for (int i = 1; i < points.size(); lastPoint = points[i++]) {
            int dx = points[i][0] > lastPoint[0] ? points[i][0] - lastPoint[0] : lastPoint[0] - points[i][0];
            int dy = points[i][1] > lastPoint[1] ? points[i][1] - lastPoint[1] : lastPoint[1] - points[i][1];
            cout << lastPoint[1] << " " << points[i][1] << endl;
            ret += max(dx, dy);
        }
        return ret;
    }
};
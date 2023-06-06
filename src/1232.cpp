/**
 * Check If It Is a Straight Line
 * 
 * You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double k;
        double b;

        vector<int> x0 = coordinates[0];
        vector<int> x1 = coordinates[1];

        if (x0[0] != x1[0]) {
            k = (x0[1] - x1[1]) * 1. / (x0[0] - x1[0]);
            b = x0[1] - k * x0[0];

            for (int i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][1] != k * coordinates[i][0] + b) {
                    return false;
                }
            }
        } else {
            for (int i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][0] != coordinates[0][0]) {
                    return false;
                }
            }
        }

        return true;
    }
};
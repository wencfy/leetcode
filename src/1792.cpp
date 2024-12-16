#include "iostream"
#include "vector"
#include "queue"
using namespace std;

class Solution {
public:
    class Compare {
    public:
        bool operator() (pair<int, int> a, pair<int, int> b) {
            double a_inc = (a.first + 1.) / (a.second + 1) - a.first * 1. / a.second;
            double b_inc = (b.first + 1.) / (b.second + 1) - b.first * 1. / b.second;
            return a_inc < b_inc;
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;

        for (auto c: classes) {
            q.push({c[0], c[1]});
        }

        while (extraStudents--) {
            auto p = q.top();
            q.pop();

            // cout << p.first << " " << p.second << endl;

            q.push({p.first + 1, p.second + 1});
        }

        double total = 0;
        while (!q.empty()) {
            auto top = q.top();
            q.pop();

            total += top.first * 1. / top.second;
        }

        return total / classes.size();
    }
};
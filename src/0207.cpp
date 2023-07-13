/**
 * Course Schedule
 * 
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
 * 
 * - For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1
 * 
 * Return true if you can finish all courses. Otherwise, return false.
 */

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> nextCourses(numCourses);

        for (auto pair: prerequisites) {
            nextCourses[pair[1]].push_back(pair[0]);
            in[pair[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!in[i]) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            for (auto course: nextCourses[top]) {
                in[course]--;
                if (!in[course]) {
                    q.push(course);
                }
            }
        }

        for (int i: in) {
            if (i) {
                return false;
            }
        }
        return true;
    }
};
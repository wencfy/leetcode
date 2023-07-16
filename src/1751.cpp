/**
 * Maximum Number of Events That Can Be Attended II
 * 
 * You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
 * 
 * You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
 * 
 * Return the maximum sum of values that you can receive by attending events.
 */

#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

class Solution {
    vector<vector<int>> dp;
    vector<vector<int>> events;
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(),
            [](vector<int> a, vector<int> b) {
                return a[0] < b[0];
            }
        );
        this->events = events;

        dp = vector<vector<int>>(k + 1, vector<int>(events.size(), -1));

        return dfs(0, k);
    }

    int dfs(int curIdx, int count) {
        if (count == 0 || curIdx == events.size()) {
            return 0;
        }
        if (dp[count][curIdx] != -1) {
            return dp[count][curIdx];
        }
        
        int nextIdx = bSearch(events[curIdx][1]);
        dp[count][curIdx] = max(dfs(curIdx + 1, count), events[curIdx][2] + dfs(nextIdx, count - 1));
        return dp[count][curIdx];
    }

    // return the id of the next event
    int bSearch(int val) {
        int low = 0;
        int high = events.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (events[mid][0] <= val) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
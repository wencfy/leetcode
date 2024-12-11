#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });

        vector<int> suffix(events.size(), 0);
        suffix[events.size() - 1] = events[events.size() - 1][2];
        for (int i = events.size() - 2; i >= 0; i--) {
            suffix[i] = max(events[i][2], suffix[i + 1]);
        }

        int max_value = 0;
        for (int i = 0; i < events.size(); i++) {
            max_value = max(max_value, events[i][2]);

            int low = i + 1;
            int high = events.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (events[mid][0] <= events[i][1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (low < events.size()) {
                max_value = max(max_value, events[i][2] + suffix[low]);
            }
        }
        return max_value;
    }
};
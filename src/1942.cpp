#include "iostream"
#include "vector"
#include "queue"
#include "map"
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int tArr = times[targetFriend][0];

        sort(times.begin(), times.end(), [](auto a, auto b) {
            return a[0] < b[0];
        });

        map<int, vector<int>> mp;

        int cur = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        int idx = 0;
        for (int i = 0; i < tArr; i++) {
            if (mp.find(i) != mp.end()) {
                for (int chair: mp[i]) {
                    q.push(chair);
                }
            }
            if (i == times[idx][0]) {
                int chair;
                if (q.empty()) {
                    chair = cur++;
                } else {
                    chair = q.top();
                    q.pop();
                }
                if (mp.find(times[idx][1]) != mp.end()) {
                    mp[times[idx][1]].push_back(chair);
                } else {
                    mp[times[idx][1]] = {chair};
                }
                idx++;
            }
        }

        if (mp.find(tArr) != mp.end()) {
            for (int chair: mp[tArr]) {
                q.push(chair);
                cout << chair << " " << q.top() << endl;
            }
            cout << q.top() << endl;
        }

        if (q.empty()) {
            return cur;
        } else {
            return q.top();
        }
    }
};
#include "iostream"
using namespace std;

class Solution {
public:
    class Compare {
        public:
        bool operator()(pair<int, string> a, pair<int, string> b) {
            return a.first < b.first;
        }
    };
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;
        if (a) {
            q.push({a, "a"});
        }
        if (b) {
            q.push({b, "b"});
        }
        if (c) {
            q.push({c, "c"});
        }
        
        string ret = "";
        string prev = "";
        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            if (top.second != prev) {
                if (top.first >= 2) {
                    ret.append(top.second);
                    ret.append(top.second);
                    if (top.first > 2) {
                        q.push({top.first - 2, top.second});
                    }
                } else {
                    ret.append(top.second);
                    if (top.first > 1) {
                        q.push({top.first - 1, top.second});
                    }
                }
                prev = top.second;
            } else if (!q.empty()) {
                auto secTop = q.top();
                q.pop();
                ret.append(secTop.second);
                prev = secTop.second;
                if (secTop.first > 1) {
                    q.push({secTop.first - 1, secTop.second});
                }
                q.push({top.first, top.second});
            } else {
                return ret;
            }
        }
        return ret;
    }
};
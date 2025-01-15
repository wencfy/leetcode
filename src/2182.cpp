#include "iostream"
#include "queue"
#include "map"
using namespace std;

class Solution {
public:
    class Compare {
        public:
        bool operator()(pair<char, int> p1, pair<char, int> p2) {
            return p1.first < p2.first;
        }
    };
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> q;

        map<char, int> mp;
        for (char c: s) {
            if (mp.find(c) != mp.end()) {
                mp[c]++;
            } else {
                mp[c] = 1;
            }
        }

        for (auto p: mp) {
            q.push(p);
        }

        string ret = "";

        while (!q.empty()) {
            
        }
    }
};
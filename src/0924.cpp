#include "iostream"
#include "map"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> fa;
    int find(int x) {
        int p = x;
        while (fa[p] != p) {
            p = fa[p];
        }
        fa[x] = p;
        return fa[x];
    }

    void unon (int x, int y) {
        int rx = find(x);
        int ry = find(y);
        fa[ry] = rx;
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        fa = vector<int>(graph.size());

        for (int i = 0; i < fa.size(); i++) {
            fa[i] = i;
        }

        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (graph[i][j]) {
                    unon(i, j);
                }
            }
        }

        // setNo -> [malwareCnt, malwareNo, cnt]
        map<int, vector<int>> mp;
        int cnt = 0;
        int no = initial[0];
        for (int i: initial) {
            if (no > i) {
                no = i;
            }
        }
        for (int i = 0; i < fa.size(); i++) {
            int no = find(i);
            bool isMal = false;
            for (int mal: initial) {
                if (mal == i) {
                    isMal = true;
                    break;
                }
            }

            if (mp.find(no) == mp.end()) {
                if (isMal) {
                    mp[no] = {1, i, 1};
                } else {
                    mp[no] = {0, -1, 1};
                }
            } else {
                if (isMal) {
                    int malNo = mp[no][1] == -1 ? i : malNo;
                    mp[no] = {mp[no][0] + 1, malNo, mp[no][2] + 1};
                } else {
                    mp[no] = {mp[no][0], mp[no][1], mp[no][2] + 1};
                }
            }
        }

        for (auto p: mp) {
            auto arr = p.second;
            if (arr[0] == 1) {
                if (cnt < arr[2]) {
                    cnt = arr[2];
                    no = arr[1];
                } else if (cnt == arr[2]) {
                    if (no > arr[1]) {
                        no = arr[1];
                    }
                }
            }
        }
        return no;
    }
};
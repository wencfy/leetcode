#include "iostream"
#include "vector"
#include "queue"
#include "map"
#include "set"
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> con;
        for (auto ticket: tickets) {
            if (con.find(ticket[0]) == con.end()) {
                con[ticket[0]] = multiset<string>();
                con[ticket[0]].insert(ticket[1]);
            } else {
                con[ticket[0]].insert(ticket[1]);
            }
        }

        for (auto a: con) {
            cout << a.first << ":: ";
            while (!a.second.empty()) {
                cout << *a.second.begin() << " ";
                a.second.erase(a.second.begin());
            }
            cout << endl;
        }

        vector<string> path;
        string cur = "JFK";
        // path.push_back(cur);
        // while (true) {
        //     if (!(con[cur].empty())) {
        //         path.push_back(*con[cur].begin());
        //         con[cur].erase(con[cur].begin());
        //         cur = path[path.size() - 1];
        //     } else {
        //         break;
        //     }
        // }
        dfs(cur, con, path);
        return vector<string>(path.rbegin(), path.rend());
    }

    void dfs(string cur, map<string, multiset<string>> &con, vector<string> &path) {
        // cout << cur << endl;
        while (!(con[cur].empty())) {
            string next = *con[cur].begin();
            con[cur].erase(con[cur].begin());
            dfs(next, con, path);
        }
        path.push_back(cur);
    }
};

int main() {
    // vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    // vector<vector<string>> tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    auto ret = (new Solution())->findItinerary(tickets);
    for (auto a: ret) {
        cout << a << " ";
    }
    cout << endl;
}
/**
 * Evaluate Division
 * 
 * You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
 * 
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
 * 
 * Return the answers to all queries. If a single answer cannot be determined, return -1.0.
 */

#include "iostream"
#include "vector"
#include "map"
using namespace std;

class Solution {
private:
    map<string, pair<string, double>> valueMap;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            string s0 = equations[i][0];
            string s1 = equations[i][1];

            if (valueMap.find(s0) != valueMap.end() && valueMap.find(s1) == valueMap.end()) {
                // s0 exist, s1 x
                valueMap[s1] = pair<string, double>(s0, 1 / values[i]);
            } else if (valueMap.find(s1) != valueMap.end() && valueMap.find(s0) == valueMap.end()) {
                // s1 exist, s0 x
                valueMap[s0] = pair<string, double>(s1, values[i]);
            } else if (valueMap.find(s0) == valueMap.end() && valueMap.find(s1) == valueMap.end()) {
                // both do not exist
                if (s0 > s1) {
                    valueMap[s0] = pair<string, double>(s1, values[i]);
                    valueMap[s1] = pair<string, double>(s1, 1.);
                } else {
                    valueMap[s1] = pair<string, double>(s0, 1 / values[i]);
                    valueMap[s0] = pair<string, double>(s0, 1.);
                }
            } else {
                // both exist
                if (valueMap[s0].first != valueMap[s1].first) {
                    valueMap[valueMap[s0].first] = pair<string, double>(s1, values[i] / valueMap[s0].second);
                }
            }
            
            for (auto &p: valueMap) {
                src(p.first);
            }
        }

        // for (auto &p: valueMap) {
        //     printf("%s = %f * %s\n", p.first.c_str(), p.second.second, p.second.first.c_str());
        // }

        vector<double> ret;
        for (vector<string> query: queries) {
            string s0 = query[0];
            string s1 = query[1];
            if (
                valueMap.find(s0) != valueMap.end() && 
                valueMap.find(s1) != valueMap.end() && 
                valueMap[s0].first == valueMap[s1].first
            ) {
                ret.push_back(valueMap[s0].second / valueMap[s1].second);
            } else {
                ret.push_back(-1.);
            }
        }

        return ret;
    }

    pair<string, double> src(string s) {
        if (valueMap[s].first == s) {
            return valueMap[s]; 
        }
        
        string faS = s;
        double val = 1.;
        
        while (faS != valueMap[faS].first) {
            val *= valueMap[faS].second;
            faS = valueMap[faS].first;
        }
        valueMap[s] = pair<string, double>(faS, val);
        return valueMap[s];
    }
};

int main() {
    vector<vector<string>> equations = {{"a","b"}, {"b","c"}, {"bc","cd"}};
    vector<double> values = {1.5,2.5,5.0};
    vector<vector<string>> queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};

    for (double ans: (new Solution())->calcEquation(equations, values, queries)) {
        cout << ans << endl;
    }
}
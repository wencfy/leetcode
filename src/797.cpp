/**
 * All Paths From Source to Target
 * 
 * Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1,
 * find all possible paths from node 0 to node n - 1 and return them in any order.
 * 
 * The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> graph;

    vector<vector<int>> paths;

    void init(vector<vector<int>>& graph) {
        copy(graph.begin(), graph.end(), back_inserter(this ->graph));
        return ;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        init(graph);

        vector<int> curPath(0);
        dfs(0, curPath);
        return paths;
    }

    // deep first search
    void dfs(int index, vector<int>& curPath) {
        curPath.push_back(index);
        if (index == graph.size() - 1) {
            paths.push_back(curPath);
        } else {
            for (int next: graph[index]) {
                dfs(next, curPath);
            }
        }
        curPath.pop_back();
    }
};

int main() {
    vector<vector<int>> graph = {
        { 4, 3, 1 },
        { 3, 2, 4 },
        { 3 },
        { 4 },
        {},
    };
    vector<vector<int>> paths = (new Solution()) ->allPathsSourceTarget(graph);

    for (auto path: paths) {
        for (auto point: path) {
            cout << point << " ";
        }
        cout << endl;
    }
}
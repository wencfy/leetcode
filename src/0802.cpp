/**
 * Find Eventual Safe States
 * 
 * There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
 * 
 * A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
 * 
 * Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
 */

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> out(size, 0);
        vector<vector<int>> adj(size);

        for (int i = 0; i < size; i++) {
            for (int node: graph[i]) {
                out[i]++;
                adj[node].push_back(i);
            }
        }

        queue<int> q;

        for (int i = 0; i < size; i++) {
            if (!out[i]) {
                q.push(i);
            }
        }

        vector<bool> isSave(size, false);
        while (!q.empty()) {
            int top = q.front();
            isSave[top] = true;
            q.pop();

            for (int neighbor: adj[top]) {
                out[neighbor]--;
                if (!out[neighbor]) {
                    q.push(neighbor);
                }
            }
        }

        vector<int> ret;
        for (int i = 0; i < size; i++) {
            if (isSave[i]) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
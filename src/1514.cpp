/**
 * Path with Maximum Probability
 * 
 * You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
 * 
 * Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
 * 
 * If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.
 */

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

// TLE
// class Solution {
// private:
//     vector<vector<double>> linkMatrix;
//     vector<bool> visited;
//     int end;
//     double prob = 1.;
//     double maxProb = 0.;

// public:
//     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
//         linkMatrix = vector<vector<double>>(n, vector<double>(n, 0));
//         visited = vector<bool>(n, false);
//         this->end = end;

//         for (int i = 0; i < edges.size(); i++) {
//             auto edge = edges[i];
//             linkMatrix[edge[0]][edge[1]] = succProb[i];
//             linkMatrix[edge[1]][edge[0]] = succProb[i];
//         }

//         visited[start] = true;
//         dfs(start);

//         return maxProb;
//     }

//     void dfs(int id) {
//         if (id == end) {
//             maxProb = max(maxProb, prob);
//             return;
//         }

//         for (int i = 0; i < linkMatrix[id].size(); i++) {
//             if (linkMatrix[id][i] != 0 && !visited[i]) {
//                 prob *= linkMatrix[id][i];
//                 visited[i] = true;
//                 dfs(i);
//                 visited[i] = false;
//                 prob /= linkMatrix[id][i];
//             }
//         }
//     }
// };

// BFS
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adjList(n);
        for (int i = 0; i < succProb.size(); i++) {
            auto edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back({v, succProb[i]});
            adjList[v].push_back({u, succProb[i]});
        }

        vector<double> probs(n, 0.);
        
        queue<int> q;
        q.push(start);
        probs[start] = 1.;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto edge: adjList[cur]) {
                int next = edge.first;
                double prob = edge.second;
                
                if (probs[next] < prob * probs[cur]) {
                    probs[next] = prob * probs[cur];
                    q.push(next);
                }
            }
        }

        return probs[end];
    }
};


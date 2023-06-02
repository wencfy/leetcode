/**
 * Detonate the Maximum Bombs
 * 
 * You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt.
 * This area is in the shape of a circle with the center as the location of the bomb.
 * 
 * The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri].
 * xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.
 * 
 * You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range.
 * These bombs will further detonate the bombs that lie in their ranges.
 * 
 * Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.
*/

#include "iostream"
#include "queue"
#include "vector"
using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> linkMatrix(bombs.size(), vector<int>(0));
        for (int i = 0; i < bombs.size(); i++) {
            for (int j = 0; j < bombs.size(); j++) {
                if (j != i) {
                    if (
                        (long long) (bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]) + 
                        (long long) (bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1]) <=
                        (long long) bombs[i][2] * bombs[i][2]
                    ) {
                        linkMatrix[i].push_back(j);
                    }
                }
            }
        }

        int maxCnt = -1;
        for (int i = 0; i < bombs.size(); i++) {
            // bfs
            queue<int> q;
            vector<int> visited(bombs.size(), 0);
            q.push(i);
            visited[i] = 1;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int n: linkMatrix[cur]) {
                    if (visited[n] == 0) {
                        q.push(n);
                        visited[n] = 1;
                    }
                }
            }

            int sum = 0;
            cout << i << "\t";
            for (int v: visited) {
                cout << v << " ";
                sum += v;
            }
            cout << endl;
            if (maxCnt < sum) {
                maxCnt = sum;
            }
        }

        for (auto vec: linkMatrix) {
            for (auto i: vec) {
                printf("%d ", i);
            }
            printf("\n");
        }

        cout << maxCnt << endl;
        return maxCnt;
    }
};

int main() {
    vector<vector<int>> bombs = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    (new Solution()) ->maximumDetonation(bombs);
}
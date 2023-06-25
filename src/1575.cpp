/**
 * Count All Possible Routes
 * 
 * You are given an array of distinct positive integers locations where locations[i] represents the position of city i. You are also given integers start, finish and fuel representing the starting city, ending city, and the initial amount of fuel you have, respectively.
 * 
 * At each step, if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length and move to city j. Moving from city i to city j reduces the amount of fuel you have by |locations[i] - locations[j]|. Please notice that |x| denotes the absolute value of x.
 * 
 * Notice that fuel cannot become negative at any point in time, and that you are allowed to visit any city more than once (including start and finish).
 * 
 * Return the count of all possible routes from start to finish. Since the answer may be too large, return it modulo 109 + 7.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
    const int modulo = 1000000007;
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        // dp[city index][fuel left]
        dp = vector<vector<int>>(locations.size(), vector<int>(fuel + 1, -1));
        
        return dfs(locations, start, finish, fuel);
    }

    int dfs(vector<int>& locations, int idx, int finish, int fuel) {
        if (dp[idx][fuel] != -1) {
            cout << "*" << endl;
            cout << idx << " " << fuel << ": " << dp[idx][fuel] << endl;
            return dp[idx][fuel];
        }

        long long cnt = idx == finish;
        for (int i = 0; i < locations.size(); i++) {
            if (fuel >= abs(locations[i] - locations[idx]) && idx != i) {
                int fuelLeft = fuel - abs(locations[i] - locations[idx]);
                cnt += dfs(locations, i, finish, fuelLeft);
            }
        }
        dp[idx][fuel] = cnt % modulo;
        cout << idx << " " << fuel << ": " << dp[idx][fuel] << endl;
        return dp[idx][fuel];
    }
};

int main() {
    vector<int> locations = {2, 1, 5};
    cout << (new Solution())->countRoutes(locations, 0, 0, 3) << endl;
}
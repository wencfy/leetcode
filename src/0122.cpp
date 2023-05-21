/**
 * Best Time to Buy and Sell Stock II
 * 
 * You are given an integer array prices where prices[i]
 * is the price of a given stock on the ith day.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i - 1]) {
                profit += prices[i - 1] - buyPrice;
                buyPrice = prices[i];
            }
        }

        profit += prices.back() - buyPrice;
        return profit;
    }
};
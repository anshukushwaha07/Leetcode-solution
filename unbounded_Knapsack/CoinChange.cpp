//Number of Ways to Make Change - Unbounded Knapsack
//https://leetcode.com/problems/coin-change-2/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // base case: 1 way to make amount 0
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {

                // include coin
                if (coins[i - 1] <= j)
                    dp[i][j] = dp[i][j - coins[i - 1]];

                // exclude coin
                dp[i][j] += dp[i - 1][j];
            }
        }

        return dp[n][amount];
    }
};


int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Number of ways to make change for amount " 
         << amount << " is " << sol.change(amount, coins) << endl;
    return 0;
}
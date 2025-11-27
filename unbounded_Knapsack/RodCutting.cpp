#include <bits/stdc++.h>
using namespace std;

int MaxProfitRodCutting(vector<int>& length, vector<int>& prices, int n) {
    int len = length.size();
    vector<vector<int>> dp(len + 1, vector<int>(n + 1, 0));

    // dp[i][j] = max profit using first i pieces to get rod length j
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= n; j++) {
            if (length[i - 1] <= j) {
                // include current piece (unbounded) OR exclude it
                dp[i][j] = max(
                    prices[i - 1] + dp[i][j - length[i - 1]],  // take it (stay at i)
                    dp[i - 1][j]                               // skip it
                );
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[len][n];
}

int main() {
    vector<int> length = {1,2,3,4,5,6,7,8};
    vector<int> prices = {1,5,8,9,10,17,17,20};
    int n = 8; // length of the rod
    cout << "Maximum profit by cutting the rod of length " 
         << n << " is " << MaxProfitRodCutting(length, prices, n) << endl;
    return 0;
}

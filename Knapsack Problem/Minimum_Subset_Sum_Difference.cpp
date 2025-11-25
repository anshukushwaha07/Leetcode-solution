#include <bits/stdc++.h>
using namespace std;

int MinimumSubsetSumDifference(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();

    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

    // Initialization
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }

    // DP filling
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int minDiff = INT_MAX;

    // Only check till sum/2
    for(int s = 0; s <= sum/2; s++){
        if(dp[n][s]){
            minDiff = min(minDiff, sum - 2*s);
        }
    }

    return minDiff;
}

int main(){
    vector<int> nums = {1, 6, 11, 5};
    cout << "Minimum Subset Sum Difference is " 
         << MinimumSubsetSumDifference(nums) << endl;
    return 0;
}

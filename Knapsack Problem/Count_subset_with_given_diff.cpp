#include<bits/stdc++.h>
using namespace std;

int CountSubsetsWithGivenDiff(vector<int>& nums,int diff){
    int n= nums.size();
    int sum= accumulate(nums.begin(),nums.end(),0);

    // Check mandatory condition
    if ((sum + diff) % 2 != 0) return 0;
    int target = (sum + diff) / 2;

    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

    //initialization
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
   }
    
   for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(nums[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
   }

   return dp[n][target];
}


//using recursive approach
int CountSubsetsWithGivenDiffRecursive(vector<int>& nums, int diff, int n, int sum) {
    // Base condition
    if(n==0){
        if(sum==0 && diff==0){
            return 1;
        }
        else{
            return 0;
        }       
    }
    if(nums[n-1]<=sum){
        return CountSubsetsWithGivenDiffRecursive(nums,diff-nums[n-1],n-1,sum-nums[n-1]) + CountSubsetsWithGivenDiffRecursive(nums,diff,n-1,sum);
    }
    else{
        return CountSubsetsWithGivenDiffRecursive(nums,diff,n-1,sum);
    }
}

int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    int diff = 3;
    cout<<"Number of subsets with given difference "<<diff<<" is "<<CountSubsetsWithGivenDiff(nums,diff)<<endl;
    return 0;
}
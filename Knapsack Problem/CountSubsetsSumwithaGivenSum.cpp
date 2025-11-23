#include <bits/stdc++.h>
using namespace std;

int CountSubsetsSumwithaGivenSum(vector<int>& nums, int sum) {
    int n= nums.size();
    int dp[n+1][sum+1];

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
    return dp[n][sum];
}

int CountSubsetsSumwithaGivenSumRecursive(vector<int>& nums, int sum, int n) {
    // Base condition
    if(n==0){
        if(sum==0){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(nums[n-1]<=sum){
        return CountSubsetsSumwithaGivenSumRecursive(nums,sum-nums[n-1],n-1) + CountSubsetsSumwithaGivenSumRecursive(nums,sum,n-1);
    }
    else{
        return CountSubsetsSumwithaGivenSumRecursive(nums,sum,n-1);
    }
}

int main(){
    // vector<int>nums={2,3,5,6,8,10};
    // int sum=10;
    // cout<<"Number of subsets with sum "<<sum<<" is "<<CountSubsetsSumwithaGivenSum(nums,sum)<<endl;
    // return 0;

    vector<int>nums={2,3,5,6,8,10};
    int sum=10;
    int n= nums.size();
    cout<<"Number of subsets with sum "<<sum<<" is "<<CountSubsetsSumwithaGivenSumRecursive(nums,sum,n)<<endl;
    return 0;
}
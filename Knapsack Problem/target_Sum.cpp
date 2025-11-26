#include <bits/stdc++.h>
using namespace std;

//this nothing but count of subsets with given sum given difference problem
int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum= accumulate(nums.begin(),nums.end(),0);

        if (sum < abs(target)) return 0;
        if ((sum + target) % 2 != 0) return 0;
        int ans = (sum + target) / 2;
        vector<vector<int>>dp(n+1,vector<int>(ans+1,0));

        //initialization
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(int i=1;i<=n;i++){
            for(int j=0;j<=ans;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        return dp[n][ans];
        
    }

    //using recursive approach
    int findTargetSumWaysRecursive(vector<int>& nums, int target, int n, int sum) {
        // Base condition
        if(n==0){
            if(sum==0 && target==0){
                return 1;
            }
            else{
                return 0;
            }       
        }
        if(nums[n-1]<=sum){
            return findTargetSumWaysRecursive(nums,target-nums[n-1],n-1,sum-nums[n-1]) + findTargetSumWaysRecursive(nums,target+nums[n-1],n-1,sum);
        }
        else{
            return findTargetSumWaysRecursive(nums,target,n-1,sum);
        }
    }

    
    int main(){
        vector<int>nums={1,1,1,1,1};
        int target=3;
        cout<<"Number of ways to get target sum "<<target<<" is "<<findTargetSumWays(nums,target)<<endl;
        return 0;
    }
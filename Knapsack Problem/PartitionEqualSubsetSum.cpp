
partitionEqualSubsetSum(vector<int>&nums){
    int n= nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }

     if(sum%2!=0){
        return false;
     }   

     int targetSum=sum/2;
     vector<bool> dp(targetSum + 1, false);
     dp[0]= true;

     for(int x:nums){
        for(int i=targetSum;i>=x;i--){
            dp[i]= dp[i] || dp[i - x];
        }
     }

     return dp[targetSum];   
}

int main(){
    vector<int>nums={1,5,11,5};
    if(partitionEqualSubsetSum(nums)){
        cout<<"Can be partitioned into two subsets with equal sum"<<endl;
    }
    else{
        cout<<"Cannot be partitioned into two subsets with equal sum"<<endl;
    }
    return 0;
}
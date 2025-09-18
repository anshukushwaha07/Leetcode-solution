//this is work only for sorted array
vector<int>TwoSum(vector<int>nums, int target){
    int left=0;
    int right=nums.size()-1;
    vector<int>res;

    while(left<right){
       int sum=nums[left]+nums[right];
       if(sum==target){
          res.push_back(left);
          res.push_back(right);
          return res;
       }
       else if(sum<target){
           left++;
       }
       else{
        right++;
       }
    }
    return res;
}

// onsorted arry use map 

vector<int>TwoSum_1(vector<int>nums,int target){
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        int need = target-nums[i];

        if(mp.count(need)){
            return {mp[need],i}
        }
        mp[nums[i]]=i;
    }
    return {};
}
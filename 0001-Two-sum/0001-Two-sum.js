//sorted array

function twoSum(nums,target){
    let left=0;
    let right=nums.length-1;

    while(left<right){
        let sum=nums[left]+right[left];
        if(sum==target){
            return[left,right];
        }else if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    return [];
}

// unsorted array

function twoSumUnsorted(nums,target){
    const map=new map();

    for(let i=0;i<nums.length;i++){
        let need=target-nums[i];

        if(map.has(need)){
            return [map.get(need),i];
        }

        map.set(nums[i],i);
    }

    return [];
}
int knapsack(int wt[],int val[],int w,int n){
    // Base condition
    if(n == 0 || w == 0){
        return 0;
    }

    if(wt[n-1]<=w){
        return max(
            val[n-1]+knapsack(wt,val,w-wt[n-1],n-1) //including
            ,knapsack(wt,val,w,n-1))// excluding
    }
    else if(wt[n-1]>w){
        return knapsack(wt,val,w,n-1); // Cannot include the item
    }
}
int knapsack(int wt[],int val,int w,int n){
    // Base condition
    if(n == 0 || w == 0){
        return 0;
    }

    if(wt[n-1]<=w){
        return max(
            val[n-1]+knapsack(wt,val,w,n) //including
            ,knapsack(wt,val,w,n))// excluding
    }
    else if(w[n-1]>w){
        return knapsack(wt,val,n-1); // Cannot include the item
    }
}
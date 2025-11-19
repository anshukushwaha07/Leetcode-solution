/* this is recursive apporach to solve 0/1 knapsack problem */

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


/* 
Time Complexity: O(2^n)
Space Complexity: O(1) 
*/


/* Now we will implement the dynamic programming approach to solve 0/1 knapsack problem */

/* Approach

- there is only small change in the recursive approach
- we will create a 2D array dp[n+1][w+1] where n is number of items and w is maximum weight capacity of knapsack
- dp[i][j] will represent the maximum value that can be obtained with first i items and weight capacity j
- we will fill this dp array in bottom-up manner
- we can declare the dp array as global , we can also declare it inside the function or if pass from the main function
- in this implementaionan we will declare as global 
*/


int dp[1001][1001]; // global declaration of dp array
memset(dp,-1,sizeof(dp)); // initializing all values to -1

int knapsack(int wt[],int val[],int w,int n){
    // Base condition
    if(n == 0 || w == 0){
        return 0;
    }

    // check if the value is already computed
    if(dp[n][w] != -1){
        return dp[n][w];
    }

    if(wt[n-1]<=w){
        dp[n][w] = max(
            val[n-1]+knapsack(wt,val,w-wt[n-1],n-1) //including
            ,knapsack(wt,val,w,n-1)); // excluding
        return dp[n][w];
    }
    else if(wt[n-1]>w){
        dp[n][w] = knapsack(wt,val,w,n-1); // Cannot include the item
        return dp[n][w];
    }
}


// 0 1 knapsack top down approach   

int knapsack(int wt[],int val[],int w,int n){

    int dp[n+1][w+1];

    // initializing the first row and first column to 0
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    // filling the dp array
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max(
                    val[i-1]+dp[i-1][j-wt[i-1]], // including
                    dp[i-1][j] // excluding
                );
            }
            else{
                dp[i][j] = dp[i-1][j]; // cannot include the item
            }
        }
    }

    return dp[n][w]; // maximum value that can be obtained with n items and weight capacity w
}
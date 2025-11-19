// C++ program to find if there is a subset with a given sum

//  arr[]: [3, 34, 4, 12, 5, 2]
//  sum: 9

#include <bits/stdc++.h>
using namespace std;    
// using top down approach

bool subsetSum(int arr[], int n, int sum) {
    bool t[n + 1][sum + 1];
    // initialization
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++)
        {
            if(i==0){
                t[i][j]=false;
            }
            if(j==0){
                t[i][j]=true;
            }
        }
    } 

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[n][sum];
    
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subsetSum(arr, n, sum) == true)
        cout << "Found a subset with given sum" << endl;
    else
        cout << "No subset with given sum" << endl;
    return 0;
}



//  subset sum using  recursion 

bool subsetSum(int arr[],int n,int sum){
    // base condition
    if(sum==0){
        return true;
    }
    if(n==0){
        return false;
    }

    if(arr[n-1]<=sum){
        return subsetSum(arr,n-1,sum-arr[n-1]) || subsetSum(arr,n-1,sum);
    }
    else if(arr[n-1]>sum){
        return subsetSum(arr,n-1,sum);
    }
}


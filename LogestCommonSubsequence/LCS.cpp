// Recursive approach to find the length of Longest Common Subsequence
#include <iostream>
#include <vector>
using namespace std;    

int LCSRecursive(string &s1,string &s2,int n,int m){
    if(m==0 || n==0){
        return 0;   
    }

    if(s1[n-1]==s2[m-1]){
        return 1+LCSRecursive(s1,s2,n-1,m-1);
    }else{
        return max(LCSRecursive(s1,s2,n-1,m), LCSRecursive(s1,s2,n,m-1));
    }
}

// Dynamic Programming approach to find the length of Longest Common Subsequence top down 

int LCSDP(string &s1,string &s2,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

// LCS Bottom up approach   

int LCSBottomUp(string &s1,string &s2,int n,int m){

    int t[n+1][m+1];

    if(n==0 || m==0){
        return 0;
    }

    if(s1[n-1]==s2[m-1]){
        t[n][m]= 1+LCSBottomUp(s1,s2,n-1,m-1);
    }else{
        t[n][m]= max(LCSBottomUp(s1,s2,n-1,m), LCSBottomUp(s1,s2,n,m-1));
    }   
    return t[n][m];
}

int main(){
    string s1="abcdgh";
    string s2="abedfhr";

    int n=s1.length();
    int m=s2.length();

    cout<<"Length of Longest Common Subsequence is "<<LCSRecursive(s1,s2,n,m)<<endl;

    cout<<"Length of Longest Common Subsequence using DP is "<<LCSDP(s1,s2,n,m)<<endl;
    
    cout<<"Length of Longest Common Subsequence using Bottom Up is "<<LCSBottomUp(s1,s2,n,m)<<endl;
    return 0;
}

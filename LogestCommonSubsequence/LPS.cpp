//longest plaindromic subsequence
#include <bits/stdc++.h>
using namespace std;

int LPSLength(string &s,int n){
    string revS=s;
    reverse(revS.begin(),revS.end());

    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==revS[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}


// seconde method using LCS


int LCSPalindrom(string &s1,string &s2,int n,int m){

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

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

int plaindromicLength(string &s){
    string revS=s;
    reverse(revS.begin(),revS.end());
    return LCSPalindrom(s,revS,s.length(),revS.length());
}


int main(){
    string s;
    cin>>s;
    int n=s.length();

    cout<<"Length of Longest Palindromic Subsequence is: "<<LPSLength(s,n)<<endl;

    return 0;
}
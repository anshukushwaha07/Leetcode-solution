// Minimum Insertion Steps to Make a String Palindrome leetcode pronlem link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// first method using LPS

// in this use of size of string - LPS length to get the minimum insertion to make a string palindrome 
#include <bits/stdc++.h>
using namespace std;    


int minInsertions(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        int n=s.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
               if(s[i-1]==s1[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        }

        return (n-dp[n][n]);
    }


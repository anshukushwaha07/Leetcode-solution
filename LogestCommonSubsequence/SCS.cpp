// sortest common supersequence
#include <bits/stdc++.h>
using namespace std;    

int LCSLength(string &s1,string &s2,int n,int m){

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

int SCSLength(string &s1,string &s2,int n,int m){
    int lcsLength= LCSLength(s1,s2,n,m);
    return (n+m - lcsLength);
}

string SCSString(string &s1,string &s2,int n,int m){
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

    // now we will build the SCS string from the dp table
    int i=n,j=m;
    string scs="";

    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            scs.push_back(s1[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                scs.push_back(s1[i-1]);
                i--;
            }else{
                scs.push_back(s2[j-1]);
                j--;
            }
        }
    }

    while(i>0){
        scs.push_back(s1[i-1]);
        i--;
    }

    while(j>0){
        scs.push_back(s2[j-1]);
        j--;
    }

    reverse(scs.begin(),scs.end());
    return scs;
}

int main() {
    string s1="AGGTAB";
    string s2="GXTXAYB";

    int n=s1.length();
    int m=s2.length();

    cout<<"Length of Shortest Common Supersequence is "<< SCSLength(s1,s2,n,m)<<endl;
    cout<<"The Shortest Common Supersequence is "<< SCSString(s1,s2,n,m)<<endl;
    return 0;
}   
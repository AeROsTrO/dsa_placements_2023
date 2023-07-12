#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

int rec(string&s, string&t,  int m, int n, string &ans){
  if(m==0 || n==0)return 0;
  if(s[m-1]==t[n-1])return 1+rec(s, t, m-1, n-1, ans);
  else return max(rec(s, t, m, n-1, ans), rec(s, t, m-1, n, ans));
}

int mem(string &s, string &t, int m, int n, vector<vector<int>>&dp){
    if(m==0 || n==0)return dp[m][n]=0;
    if(dp[m][n]!=-1)return dp[m][n];
    if(s[m-1]==t[n-1])dp[m][n]=1+mem(s, t, m-1, n-1, dp);
    return dp[m][n]=max(mem(s, t, m-1, n, dp), mem(s, t, m, n-1, dp));
}

int tab(string &s, string &t, vector<vector<int>>&dp){
    int m=s.length(), n=t.length();
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(!i || !j)dp[i][j]=0;// base case(when either of them is empty string no common subsequence)
            else{
                dp[i][j]=(s[i-1]==t[j-1])?1+dp[i-1][j-1]:max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
string getLCS(string &s, string &t){
    int m=s.length(), n=t.length();
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
    tab(s, t, dp);
    string ans="";
    int i=m, j=n;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1])ans+=s[i-1],i--, j--;
        else{
            if(dp[i-1][j]>dp[i][j-1])i--;
            else j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string s, t;
    cin>>s>>t;
    string ans="";
    // cout<<rec(s, t, s.length(), t.length(), ans);
    cout<<getLCS(s, t);
    return 0;
}
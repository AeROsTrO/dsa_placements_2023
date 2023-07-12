#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define fl(i, l, r, k) for (int i = l; i < r; i += k)
#define vi vector<int>
#define vc vector<char>
#define fe(i, v) for (int i : v)
#define pb push_back
#define pp pop_back
#define in(n) cin >> n
#define out(n) cout << n
#define mii map<int, int>
#define umii unordered_map<int, int>
#define mci map<char, int>
#define pqi priority_queue<int>
#define pii pair<int, int>
#define pci pair<char, int>
#define vpii vector<pair<int, int>>
#define sti stack<int>
#define stc stack<char>
#define qi queue<int>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define sor(v) sort(all(v))
#define readd(a, n) fl(i, 0, n, 1) cin >> a[i];
#define writee(a) fl(i, 0, n, 1) cout << a[i];
#define ln cout << nl;
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &i : v)
        cin >> i;
    return in;
}
#define sp ' '
template <typename T>
void printArr(vector<T> &v)
{
    for (auto &i : v)
        cout << i << ' ';
}
// per aspera ad astra
//O(n^3) O(1)
string brute(string &s)
{
    int start = 0, maxlen = 1;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            bool flag = true;
            for (int k = 0; k < (j - i + 1) / 2; k++)
            {
                if (s[i + k] != s[j - k])
                    flag = false;
            }
            if (flag && j - i + 1 > maxlen)
                maxlen = j - i + 1, start = i;
        }
    }
    return s.substr(start, maxlen);
}

// found on leetcode
//O(n^2) O(1)
string longestPalindrome(string s)
{
    int n = s.size();
    if (n < 2)
        return s;
    int maxLen = 1, start = 0;
    int low, high;
    for (int i = 0; i < n; i++)
    {
        low = i - 1;
        high = i + 1;
        while (high < n && s[high] == s[i])
            high++;
        while (low >= 0 && s[low] == s[i])
            low--;
        while (low >= 0 && high < n && s[low] == s[high])
        {
            high++;
            low--;
        }
        int len = high - low - 1;
        if (maxLen < len)
        {
            maxLen = len;
            start = low + 1;
        }
    }
    return s.substr(start, maxLen);
}
//O(n^2) O(n^2)
string getLongestPalindromicSubstringLength(string &s);
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int ans = 1;
    vector<vi> dp(n, vi(n, 0)); // can use bool to decrease space (actually gemnius)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i == j)
                dp[i][j] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = (s[i] == s[i + 1]);
        if (dp[i][i + 1] == 1)
            ans = 2;
    }
    for (int k = 3; k <= n; k++)
    { // k is length
        for (int i = 0; i <= n - k; i++)
        {
            int j = i + k - 1;
            if (s[i] == s[j] and dp[i + 1][j - 1]) // first and last letters should be same and the rest part should be palindrome
            {
                dp[i][j] = 1;
                ans = max(ans, k);
            }
        }
    }
    cout << ans << " " << getLongestPalindromicSubstring(s);
}
string getLongestPalindromicSubstring(string &s)
{
    int n = s.length();
    vector<vi> dp(n, vi(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    int ans = 0;
    int sInd = 0;
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = (s[i] == s[i + 1]);
        if (dp[i][i + 1] == 1)
            ans = 2, sInd = i;
    }

    for (int k = 3; k <= n; k++)
    {
        for (int j = 0; j < n - k + 1; j++)
        {
            int i = j + k - 1;
            if (s[i] == s[j] and dp[j + 1][i - 1])
            {
                dp[j][i] = 1;
                if (k > ans)
                {
                    sInd = j;
                    ans = k;
                }
            }
        }
    }
    return s.substr(sInd, ans);
}
int getNumberOfPalindromicSubstrings(string &s){
     
        int ans=0;
        int n=s.length();
        if(n==1)return 1;
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++)dp[i][i]=1;ans+=n;
        for(int i=0; i<n-1; i++){dp[i][i+1]=(s[i]==s[i+1]);if(dp[i][i+1]==1)++ans;}
        for(int k=3; k<=n; k++){
            for(int l=0; l<n-k+1; l++){
                int m=l+k-1;
                if(s[l]==s[m] and dp[l+1][m-1]){
                    ++ans;
                    dp[l][m]=1;
                }
            }
        }
        return ans;
}
int main()
{
    FIO;
    string s;
    cin >> s;
    cout << brute(s);
    return 0;
}
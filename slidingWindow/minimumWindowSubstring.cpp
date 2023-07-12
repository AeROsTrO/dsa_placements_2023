#include <bits/stdc++.h>
using namespace std;
// problem description here
//  Given two strings s and t of lengths m and n respectively, return the minimum window
//  substring
//   of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
//  The testcases will be generated such that the answer is unique.

string minWindow(string s, string t)
{
    int n = s.length();
    unordered_map<char, int> m;
    for (char c : t)
        m[c]++;
    int ct = t.length(), i = 0, j = 0, minl = INT_MAX, mins = 0;
    while (j < n)
    {
        if (m[s[j]] > 0)
            --ct;
        m[s[j]]--;
        j++;
        while (ct == 0)
        {
            if (j - i < minl)
            {
                minl = j - i;
                mins = i;
            }
            m[s[i]]++;
            if (m[s[i]] > 0)
                ++ct;
            i++;
        }
    }
    return minl == INT_MAX ? "" : s.substr(mins, minl);
}
int main()
{
    string s, t;cin>>s>>t;
    cout<<minWindow(s, t);
    return 0;
}
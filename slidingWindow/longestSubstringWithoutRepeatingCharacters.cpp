#include <bits/stdc++.h>
using namespace std;
//problem description here
// iven a string s, find the length of the longest substring without repeating characters.
 int lengthOfLongestSubstring(string s) {
        unordered_map<int, int>m;
        if(s.empty())return 0;
        int n=s.length();
        int i=0, j=0;
        int ans=INT_MIN;
        while(j<n){
            m[s[j]]++;
            if(j-i+1>m.size()){
                ans=max(ans, (int)m.size());
                if(--m[s[i]]==0)m.erase(s[i]);
                i++;
                j++;
            }
            else j++;
        }
        return ans=max(ans, (int)m.size());
    }
int main()
{
    string s;cin>>s;
    cout<<lengthOfLongestSubstring(s);
    return 0;
}
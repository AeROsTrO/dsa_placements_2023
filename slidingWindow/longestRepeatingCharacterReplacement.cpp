#include <bits/stdc++.h>
using namespace std;
//problem description here
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

//brute force would be to change the char and try every substring
int soln(string&s, int k){
  int n=s.length();
        if(s.size()==0)return 0;
        vector<int>arr(128);
        int i=0, lc=0;
        for(int j=0; j<s.size(); j++){
            lc=max(lc, ++arr[s[j]]);
            // We are allowed to have at most k replacements in the window...
            // So, if max character frequency + distance between beg and end        is greater than k...
            // That means we have met a largest possible sequence, we can move  the window to right...
            int window=j-i+1;
            if(window-lc>k)arr[s[i++]]--;
        }
        return s.length()-i;
    }
int main()
{
    string s;cin>>s;
    
    return 0;
}
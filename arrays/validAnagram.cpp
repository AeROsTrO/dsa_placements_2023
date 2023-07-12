#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

bool isAnagram(string &s, string &t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
        //tc=O(nlogn)
        
        // map approach
        if(s.length()!=t.length())return false;
        unordered_map<char, int>m;
        for(int i=0; i<s.length(); i++){
            m[s[i]]++;
            m[t[i]]--;
        }
        for(auto i:m){
            if(i.second)return false;
        }
        return true;
        //tc=O(n) sc=O(n)
        
        //array approach similar to map
        int arr[26]={0};
        for(int i=0; i<s.length(); i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for(int i=0; i<26; i++)if(arr[i])return false;
        return true;
        //tc=O(n) sc=O(1)
}

int main()
{
 
return 0;
}
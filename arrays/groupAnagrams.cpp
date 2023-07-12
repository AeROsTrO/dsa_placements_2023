
#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string, vector<string>>m;
        for(auto i:strs){
            string x=i;
            sort(x.begin(), x.end());
            m[x].push_back(i);
        }
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
int main()
{
 
    return 0;
}
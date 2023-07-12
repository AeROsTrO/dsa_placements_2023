#include <bits/stdc++.h>
using namespace std;
// problem description here
//  A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
//  Given a string s, return true if it is a palindrome, or false otherwise.
bool isPal(string&s){
    int n=s.length();
    int i=0, j=n-1;
    while(i<j){
        if(s[i++]!=s[j--])return false;
    }
    return true;
}
bool isPal(string &s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
}
bool isPalindrome(string s)
{
    string t = "";
    for (char i : s)
    {
        if ((i >= 'a' && i <= 'z') || (i >= '0' && i <= '9'))
        {
            t += i;
        }
        if (i >= 'A' && i <= 'Z')
        {
            t += i + 32;
        }
    }
    // cout<<t;
    return isPal(t);
}
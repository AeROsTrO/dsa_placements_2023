#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
bool isValid(string&s){
    int n=s.size();
    stack<char>st;
    for(int i=0; i<n; i++){
        char ch=s[i];
        if(st.empty() || ch=='(' || ch=='{' || ch=='[')st.push(ch);
        else{
            if((ch=='}' && st.top()=='{') || (ch==']' && st.top()=='[') || (ch=='(' && st.top()==')'))st.pop();
            else return false;
        }
    }
    return st.empty();
}
int main()
{
 
return 0;
}
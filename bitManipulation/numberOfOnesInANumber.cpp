#include <bits/stdc++.h>
using namespace std;
//problem description here
int sol1(int n){
    // O(logn) O(1)
    //convert to binary and find number of ones
    int ct=0;
    while(n){
        if(n%2==1)++ct;
        n>>=1;
    }
    return ct;
}
int sol2(int n){
    //O(32)=O(1) O(1)
    int ct=0;
    for(int i=0; i<32; i++){
        if(((n>>i)&1)!=0)++ct;
    }
    return ct;
}
int sol3(int n){
    // O(logn) O(1)
     // when we substract n by 1, the Lowest significant 1 is affected first, thus when we use and (&) operation the other 1's stay intact and we increment count by 1
    int ct=0;
    for(int i=n; i>0; i&=(i-1))++ct;
    return ct;
}
int main()
{
    int n;cin>>n;
    cout<<sol1(n)<<" "<<sol2(n)<<" "<<sol3(n);
    return 0;
}
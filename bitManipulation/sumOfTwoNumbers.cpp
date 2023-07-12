#include <bits/stdc++.h>
using namespace std;
//problem description here
int sol1(int a, int b){
    int carry;
    while(b){
        carry=(a&b);
        a=(a^b);
        b=carry<<1;
    }
    return a;
}
int main()
{
    //0 1 2 3 4 5 6 7 8 9 
    for(int i=0; i<10; i++){
        cout<<sol1(i, i+1)<<" ";
    }
    return 0;
}
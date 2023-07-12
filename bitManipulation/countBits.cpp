#include <bits/stdc++.h>
using namespace std;
//problem description here
//sol1
int setBits(int n){
        int ct=0;
        for(int i=31; i>=0; i--){
            if(((n>>i)&1)!=0)++ct;
        }
        return ct;
    }
vector<int> countBits(int n){
    //O(n) O(1)(since return array is not counted in space complexity)
        vector<int>ans;
        for(int i=0; i<=n; i++){
            ans.push_back(setBits(i));
        }
        return ans;
}
//sol2
vector<int> countBits(int n) {
    //O(n) O(1)
        vector<int>res(n+1, 0);
        for(int i=1; i<=n; i++)
            res[i]=res[i&(i-1)]+1;
        return res;
}
//sol3
vector<int> countBits(int n) {
        vector<int>ans(n+1, 0);
        ans[0]=0;
        for(int i=1; i<=n; i++)ans[i]=ans[i/2]+i%2;
        return ans;
 }
int main()
{
    int n;cin>>n;
    return 0;
}
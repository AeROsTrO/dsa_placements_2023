#include <bits/stdc++.h>
using namespace std;
//problem description here
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

int ans(vector<int>&h){
int i=0, n=h.size(), j=n-1;
        int maxone=INT_MIN;
        while(i<j){
            maxone=max(maxone, (j-i)*min(h[i],h[j]));
            if(h[i]<h[j])++i;
            else --j;
        }
        return maxone;
}
        
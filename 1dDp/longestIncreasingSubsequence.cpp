#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence

//O(2^n) O(n)
int rec(vector<int>&nums, int ind, int prev=INT_MIN){
    if(ind==nums.size())return 0;
    return max(rec(nums, ind+1, prev), (nums[ind]>prev)+rec(nums, ind+1, max(prev, nums[ind])));
    //basically this dont take + take if larger than prev
}
// There are many unnecessary repeated calculations in the brute-force approach. We can observe that the length of increasing subsequence starting at ith element with previously picked element prev will always be the same. So we can use dynamic programming to store the results for this state and reuse again in the future.

// But it wouldn't be scalable to store the state as (i, prev) because prev element can be any number in [-1e4, 1e4] meaning we would need to declare a matrix dp[n][1e8] which won't be possible

// DP with (i, prev) as state
// Instead, we could store the state of (i, prev_i), where prev_i denotes the index of previous chosen element. Thus we would use a dp matrix where dp[i][j] will denote the longest increasing subsequence from index i when previous chosen element's index is j.
vector<vector<int>>&dp;
int mem(vector<int>&nums){
    dp.resize(nums.size(), vector<int>(1+nums.size(), -1));
    return solve(nums, 0, -1);
}
//O(n^2) O(n^2)
// Instead, we could store the state of (i, prev_i), where prev_i denotes the index of previous chosen element. Thus we would use a dp matrix where dp[i][j] will denote the longest increasing subsequence from index i when previous chosen element's index is j.

// prev_index’ also represents the index of the array. When we have not considered any element in our LIS, prev_index is -1. Therefore, prev_index can range from -1 to n-1. Now we cannot store the -1 index in our 2D array. Therefore, we would do a coordinate shift of one as follows:

int solve(vector<int>&nums, int ind, int prev_ind){
    if(ind>=nums.size())return 0;
    if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
    int take=0, dontTake=solve(nums, ind+1, prev_ind);
    if(prev_ind==-1 || nums[ind]>nums[prev_ind])take=1+solve(nums, ind+1, ind);
    return dp[ind][prev_ind+1]=max(take, dontTake);
}

// We can do better and further reduce the state stored using DP. It's redundant to store states for all i having prev as its previous element index. The length will always be greatest for the state (prev, prev) since no more elements before prev can be taken. So we can just use a linear DP where dp[i] denotes the LIS starting at index i


//O(n^2)+recursion time O(n)+recursive stack space
int solve1d(vector<int>&nums, int ind=0, int prev_ind=-1, vector<int>&dp){
    if(ind>=nums.size())return 0;
    if(dp[prev_ind+1]!=-1)return dp[prev_ind+1];
    int take=0, dontTake=solve1d(nums, ind+1, prev_ind);
    if(prev_ind==-1 || nums[ind]>nums[prev_ind])take=1+solve(nums, ind+1, ind);
    dp[prev_ind+1]=max(take, dontTake);
}
//O(n^2) O(n)
// We can solve it iteratively as well. Here, we use dp array where dp[i] denotes the LIS ending at index i. We can always pick a single element and hence all dp[i] will be initialized to 1.
// For each element nums[i], if there's an smaller element nums[j] before it, the result will be maximum of current LIS length ending at i: dp[i], and LIS ending at that j + 1: dp[j] + 1. +1 because we are including the current element and extending the LIS ending at j.
int tab(vector<int>&nums){
    int n=size(nums);
    int ans=1;
    vector<int>dp(n, 1);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(nums[i]>nums[j])dp[i]=max(dp[i], dp[j]+1),ans=max(dp[i], ans);
        }
    }
    return ans;
}

// In the brute-force approach, we were not sure if an element should be included or not to form the longest increasing subsequence and thus we explored both options. The problem lies in knowing if an element must be included in the sequence formed till now. Let's instead try an approach where we include element whenever possible to maximize the length and if it's not possible, then create a new subsequence and include it.

// Consider an example - [1,7,8,4,5,6,-1,9]:

// Let's pick first element - 1 and form the subseqeunce sub1=[1].
// 7 is greater than previous element so extend the sequence by picking it.   sub1=[1,7].
// Similarly, we pick 8 as well since it's greater than 7.   sub1=[1,7,8]
// Now we cant extend it further. We can't simply discard previous sequence and start with 4 nor can we discard 7,8 and place 4 instead of them because we don't know if future increasing subsequence will be of more length or not. So we keep both previous subsequence as well as try picking 4 by forming a new subsequence. It's better to form new subsequence and place 4 after 1 to maximize new sequence length. So we have sub1=[1,7,8] and sub2=[1,4]
// Can we add 5 in any of the sequence? Yes we can add it to sub2. If it wasn't possible we would have tried the same approach as in 4th step and created another subsequence list.   sub1=[1,7,8], sub2=[1,4,5]
// Similarly, add 6 to only possible list - cur2.   sub1=[1,7,8], sub2=[1,4,5,6]
// Now, -1 cant extend any of the existing subsequence. So we need to form another sequence. Notice we cant copy and use any elements from existing subsequences before -1 either, since -1 is lowest. sub1=[1,7,8], sub2=[1,4,5,6], sub3=[-1]
// Now, 9 can be used to extend all of the list. At last, we get   sub1=[1,7,8,9], sub2=[1,4,5,6,9], sub3=[-1,9]
// We finally pick the maximum length of all lists formed till now. This approach works and gets us the correct LIS but it seems like just another inefficient approach because it's costly to maintain multiple lists and search through all of them when including a new element or making a new list. Is there a way to speed up this process? Yes. We can just maintain a single list and mark multiple lists inside it. Again, an example will better explain this.

// Consider the same example as above - [1,7,8,4,5,6,-1,9]:

// Pick first element - 1 and form the subseqeunce sub=[1].

// 7 is greater than 1 so extend the existing subsequence by picking it.   sub=[1,7].

// Similarly, we pick 8 as well since it's greater than 7.   sub=[1,7,8]

// Now comes the main part. We can't extend any existing sequence with 4. So we need to create a new subsequence following 4th step previous approach but this time we will create it inside sub itself by replacing smallest element larger than 4 (Similar to 4th step above where we formed a new sequence after picking smaller elements than 4 from existing sequence).

//     [1,    4,      8]
//            ^sub2   ^sub1

// This replacement technique works because replaced elements dont matter to us
// We only used end elements of existing lists to check if they can be extended otherwise form newer lists
// And since we have replaced a bigger element with smaller one it wont affect the 
// step of creating new list after taking some part of existing list (see step 4 in above approach)
// Now, we can't extend with 5 either. We follow the same approach as step 4.

//     [1,    4,    5]
// 				 ^sub2
	
// Think of it as extending sub2 in 5th step of above appraoch
// Also, we can see sub2 replaced sub1 meaning any subsequence formed with sub2 always
// has better chance of being LIS than sub1.
// We get 6 now and we can extend the sub list by picking it.

//     [1,    4,    5,    6]
// 				       ^sub2	
// Cant extend with -1. So, Replace -

//     [-1,    4,    5,   6]
// 	  ^sub3		       ^sub2	

// We have again formed a new list internally by replacing smallest element larger than -1 from exisiting list
// We get 9 which is greater than the end of our list and thus can be used to extend the list

//     [-1,    4,    5,    6,    9]
// 	  ^sub3		              ^sub2	

// Finally the length of our maintained list will denote the LIS length = `5`. Do note that it wont give the LIS itself but just correct length of it.
// The optimization which improves this approach over DP is applying Binary search when we can't extend the sequence and need to replace some element from maintained list - sub. The list always remains sorted and thus binary search gives us the correct index of element in list which will be replaced by current element under iteration.

// Basically, we will compare end element of sub with element under iteration cur. If cur is bigger than it, we just extend our list. Otherwise, we will simply apply binary search to find the smallest element >= cur and replace it. Understanding the explanation till now was the hard part...the approach is very easy to code🙂 .

// I have used the input array itself as my maintained list. Use an auxillary array if you're restricted from modifying the input.

class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int len = 0;
        for(auto cur : A) 
            if(len == 0 || A[len-1] < cur) A[len++] = cur;             // extend
            else *lower_bound(begin(A), begin(A) + len, cur) = cur;    // replace
        return len;
    }
};
int main()
{
    
    return 0;
}
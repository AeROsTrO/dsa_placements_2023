#include <bits/stdc++.h>
using namespace std;
//problem description here
//sol1
vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if((nums[i] + nums[j] + nums[k] == 0) && i != j && j != k && k != i){
                        set.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        for(auto it : set){
            output.push_back(it);
        }
        return output;
}
//sol2
 vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0; i<n-2; i++){
            int low = i+1, high = n-1;
            while(low < high){
                if(nums[i] + nums[low] + nums[high] < 0){
                    low++;
                }
                else if(nums[i] + nums[low] + nums[high] > 0){
                    high--;
                }
                else{
                    set.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }
            }
        }
        for(auto it : set){
            output.push_back(it);
        }
        return output;
}
//sol3
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n < 3)
        return {};

    vector<vector<int>> res;
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 and nums[i] == nums[i - 1])
            continue;
        int sum = -nums[i];
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            if (nums[j] + nums[k] == sum)
            {
                res.push_back({nums[i], nums[j], nums[k]});
                while (j < k and nums[j] == nums[j + 1])
                    j++;
                while (j < k and nums[k] == nums[k - 1])
                    k--;
                j++;
                k--;
            }
            else if (nums[j] + nums[k] < sum)
                j++;
            else
                k--;
        }
    }
    return res;
}
#include <bits/stdc++.h>
using namespace std;
// problem description here
// sol1
int pivot(vector<int> &a, int l, int r)
{
    if (r < l)
        return -1;
    if (r == l)
        return l;
    int mid = l + (r - l) / 2;
    if (mid < r && a[mid] > a[mid + 1])
        return mid;
    if (mid > l && a[mid] < a[mid - 1])
        return mid - 1;
    if (a[l] < a[mid])
        return pivot(a, mid + 1, r);
    return pivot(a, l, mid - 1);
}
int bs(vector<int> &a, int l, int h, int key)
{
    if (h >= l)
    {
        int mid = l + (h - l) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            return bs(a, l, mid - 1, key);
        else
            return bs(a, mid + 1, h, key);
    }
    return -1;
}
int search(vector<int> &a, int key)
{
    int x = pivot(a, 0, a.size() - 1), n = a.size();
    if (x == -1)
        return bs(a, 0, n - 1, key);
    if (a[x] == key)
        return x;
    if (a[0] <= key)
        return bs(a, 0, x - 1, key);
    return bs(a, x + 1, n - 1, key);
}

// sol2
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (target == nums[mid])
            return mid;
        if (nums[l] <= nums[mid])
        { // this block is entered when the left array is sorted
            if (nums[l] <= target && nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (nums[r] >= target && nums[mid] <= target)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}
int main()
{

    return 0;
}
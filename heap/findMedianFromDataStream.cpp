#include <bits/stdc++.h>
using namespace std;
//problem description here
// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
class MedianFinder {
public:
    multiset<int>nums;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.insert(num);
    }
    
    double findMedian() {
        int n=nums.size();
        int fac=(n-1)/2;
        auto it=nums.begin();
        advance(it, fac);//moves the iterator fac places ahead, in this case goes to the middle element
        double median=*it;
        if(n%2==0){
            if(++it!=nums.end()){
                median+=*it;
                median/=2;
            }
        }
        return median;
    }
};

int main()
{
 
    return 0;
}

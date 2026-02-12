#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Min heap
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        long long prefixSum = 0;
        long long maxSum = LLONG_MIN;
        
        // To handle subarray starting at index 0
        minHeap.push(0);
        
        for (int num : nums) {
            prefixSum += num;
            
            long long minPrefix = minHeap.top();
            maxSum = max(maxSum, prefixSum - minPrefix);
            
            minHeap.push(prefixSum);
        }
        
        return (int)maxSum;
    }
};

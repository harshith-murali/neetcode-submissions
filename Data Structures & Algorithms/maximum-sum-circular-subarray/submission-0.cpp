class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxKadane = nums[0], currMax = 0;
        int minKadane = nums[0] , currMin = 0;
        int totalSum = 0;
        for(int x : nums){
            totalSum += x;
            currMax = max(x, currMax + x);
            maxKadane = max(maxKadane, currMax);

            currMin = min(x, currMin + x);
            minKadane = min(minKadane , currMin);
        }
        if(maxKadane < 0) return maxKadane;
        return max(maxKadane , totalSum - minKadane);
    }
};
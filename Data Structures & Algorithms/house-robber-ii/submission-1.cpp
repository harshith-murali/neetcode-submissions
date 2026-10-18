class Solution {
public:
    int solve(int start, int end, vector<int>& nums) {
        vector<int> dp(nums.size() + 2, 0);

        for (int idx = end; idx >= start; idx--) {
            int pick = nums[idx] + dp[idx + 2];
            int notPick = dp[idx + 1];

            dp[idx] = max(pick, notPick);
        }

        return dp[start];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        int excludeLast = solve(0, n - 2, nums);
        int excludeFirst = solve(1, n - 1, nums);

        return max(excludeLast, excludeFirst);
    }
};
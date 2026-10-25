class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > totalSum) return 0;
        if ((totalSum + target) % 2 != 0) return 0;

        int s1 = (totalSum + target) / 2;
        int n = nums.size();

        vector<int> dp(s1 + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int sum = s1; sum >= nums[i]; sum--) {
                dp[sum] += dp[sum - nums[i]];
            }
        }

        return dp[s1];
    }
};
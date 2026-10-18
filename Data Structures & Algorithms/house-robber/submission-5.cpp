class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2, 0);

        for(int idx=n-1; idx>=0; idx--){
            int pick = nums[idx] + dp[idx + 2];
            int notPick = dp[idx+1];
            dp[idx] = max(pick , notPick);
        }
        return dp[0];
    }
};

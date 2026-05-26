class Solution {
public:
    int solve(int idx, int prev_idx , vector<vector<int>>& dp, vector<int>& nums){
        int n = nums.size();
        if(idx == n) return 0;
        if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];
        int notTake = solve(idx+1 , prev_idx, dp , nums);
        int take = 0;
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
           take  = 1 + solve(idx+1, idx, dp , nums);
        }
       return dp[idx][prev_idx + 1] = max(take , notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int> (n+1, -1));
        return solve(0 , -1 , dp , nums);
    }
};

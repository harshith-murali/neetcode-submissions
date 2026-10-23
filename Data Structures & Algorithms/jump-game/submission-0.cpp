class Solution {
public:
    bool f(vector<int>& nums, int n , int idx,vector<int>& dp){
        if(idx == n-1) return true;
        if(idx >= n) return false;
        if(dp[idx] != -1) return dp[idx];
        for(int i=1; i<=nums[idx]; i++){
            if(f(nums, n , idx + i, dp)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        return f(nums, n, 0 , dp);
    }   
};

class Solution {
public:
    int f(int i, vector<int>& dp, vector<int>& cost){
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int a = cost[i] + f(i+1, dp, cost);
        int b = cost[i] + f(i+2 , dp , cost);
        return dp[i] = min(a, b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(f(0,dp, cost), f(1,dp,cost));
    }
};

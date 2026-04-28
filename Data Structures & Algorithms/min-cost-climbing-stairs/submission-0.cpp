class Solution {
public:
    int f(vector<int>& cost,int idx,vector<int>&dp){
        if(idx == 0 || idx == 1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int fs = f(cost , idx-1,dp) + cost[idx-1];
        int ss = f(cost , idx-2,dp) + cost[idx-2];
        return dp[idx] = min(fs , ss);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp (n+1 , -1);
        return f(cost , n , dp);
    }
};

class Solution {
public:
    int f(int idx, int remaining, vector<int>& coins, vector<vector<int>>& dp){
        if(idx == 0){
            if(remaining % coins[0] == 0)
                return remaining / coins[0];
            else
                return 1e9;
        }

        if(dp[idx][remaining] != -1) 
            return dp[idx][remaining];

        int notTake = f(idx - 1, remaining, coins, dp);

        int take = 1e9;
        if(coins[idx] <= remaining)
            take = 1 + f(idx, remaining - coins[idx], coins, dp);

        return dp[idx][remaining] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = f(n - 1, amount, coins, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};
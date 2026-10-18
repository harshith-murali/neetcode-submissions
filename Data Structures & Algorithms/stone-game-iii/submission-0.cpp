 class Solution {
public:
    int f(int i, vector<int>& dp, vector<int>& stones) {
        int n = stones.size();
        if (i >= n) return 0;
        if (dp[i] != INT_MAX) return dp[i];

        int result = stones[i] - f(i + 1, dp, stones);

        if (i + 1 < n)
            result = max(result, stones[i] + stones[i + 1]
                                 - f(i + 2, dp, stones));

        if (i + 2 < n)
            result = max(result, stones[i] + stones[i + 1] + stones[i + 2]
                                 - f(i + 3, dp, stones));

        return dp[i] = result;
    }

    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n, INT_MAX);

        int diff = f(0, dp, stones);
        if (diff < 0) return "Bob";
        if (diff > 0) return "Alice";
        return "Tie";
    }
};
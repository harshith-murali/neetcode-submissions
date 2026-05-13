class Solution {
public:
    int start = 0;
    int maxLen = 1;

    bool helper(string& s, int i, int j,
                vector<vector<int>>& dp) {

        if (i >= j) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            dp[i][j] = helper(s, i + 1, j - 1, dp);

            if (dp[i][j] && (j - i + 1) > maxLen) {
                maxLen = j - i + 1;
                start = i;
            }
        } else {
            dp[i][j] = false;
        }

        return dp[i][j];
    }
    string longestPalindrome(string s) {
         int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                helper(s, i, j, dp);
            }
        }

        return s.substr(start, maxLen);
    }
};

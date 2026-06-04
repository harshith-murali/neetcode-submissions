class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();

        long long sumN = n * (n + 1) / 2;
        long long sumSquareN = n * (n + 1) * (2 * n + 1) / 6;

        long long currSumN = 0;
        long long currSumSquareN = 0;

        for (int i = 0; i < n; i++) {
            currSumN += nums[i];
            currSumSquareN += 1LL * nums[i] * nums[i];
        }

        long long val1 = currSumN - sumN;
        long long val2 = currSumSquareN - sumSquareN;

        val2 /= val1;

        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};
class Solution {
public:
    bool subsets(vector<int>& nums, int target) {
        int n = nums.size();

        vector<bool> prev(target + 1, false);
        prev[0] = true;

        if (nums[0] <= target) {
            prev[nums[0]] = true;
        }

        for (int i = 1; i < n; i++) {
            vector<bool> curr(target + 1, false);
            curr[0] = true;

            for (int tar = 1; tar <= target; tar++) {
                bool notTake = prev[tar];
                bool take = false;

                if (nums[i] <= tar) {
                    take = prev[tar - nums[i]];
                }

                curr[tar] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }

    bool canPartition(vector<int>& nums) {
        int totSum = accumulate(nums.begin(), nums.end(), 0);

        if (totSum % 2 != 0) return false;

        return subsets(nums, totSum / 2);
    }
};
class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
        result.push_back(temp); // Add subset at current node

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            solve(i + 1, nums, temp, result);
            temp.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, nums, temp, result);
        return result;
    }
};
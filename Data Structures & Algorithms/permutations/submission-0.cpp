class Solution {
public:
    vector<vector<int>> res;

    void solve(vector<int>& temp, vector<int>& nums, vector<bool>& visited) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.push_back(nums[i]);

                solve(temp, nums, visited);

                temp.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        solve(temp, nums, visited);
        return res;
    }
};
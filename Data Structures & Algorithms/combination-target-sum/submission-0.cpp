class Solution {
public:
    void solve(int idx , int target, vector<vector<int>>&result , vector<int>& curr, vector<int>& nums){
        if(target == 0){
            result.push_back(curr);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            if (nums[i] > target) continue;
            curr.push_back(nums[i]);
            solve(i, target - nums[i] , result, curr, nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        solve(0 , target , result, curr, nums);
        return result;
    }
};

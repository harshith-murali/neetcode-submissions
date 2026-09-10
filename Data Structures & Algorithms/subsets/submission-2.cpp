class Solution {
public:
    void solve(int i , vector<int>& nums, vector<int>& temp, vector<vector<int>>& result){
        if(i >= nums.size()){
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i+1 , nums, temp , result);
        temp.pop_back();
        solve(i+1, nums, temp, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        solve(0 , nums , temp, result);

        return result;
    }
};

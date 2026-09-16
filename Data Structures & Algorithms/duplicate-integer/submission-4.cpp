class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(begin(nums), end(nums));
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] == nums[i]){
                return true;
            }
        }
        return false;
    }
};
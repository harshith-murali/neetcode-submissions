class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(begin(nums) , end(nums));
        reverse(nums.begin() , nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
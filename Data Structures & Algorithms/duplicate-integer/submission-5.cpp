class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set st(begin(nums), end(nums));
        return st.size() != nums.size();
    }
};
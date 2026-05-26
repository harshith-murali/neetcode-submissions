class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for(int val: nums){
            ans.push_back(val);
        }
        for(int val: nums){
            ans.push_back(val);
        }
        return ans;
    }
};
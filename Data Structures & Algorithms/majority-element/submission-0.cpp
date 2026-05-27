class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int val : nums){
            mp[val]++;
        }
        for(auto it : mp){
            if(it.second > n/2){
                return it.first;
            }
        }
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = 0;
        int cnt = 0;

        for(int val:nums){
            if(cnt == 0){
                candidate = val;
            }
            if(val == candidate){
                cnt++;
            }else{
                cnt--;
            }
        }
        return candidate;
    }
};
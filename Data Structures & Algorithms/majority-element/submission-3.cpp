class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = 0, count = 0;
        for(int num : nums){
            if(num == candidate){
                count++;
            }
            else if(count == 0){
                candidate = num;
            }else{
                count++;
            }
        }
        return candidate;
    }
};
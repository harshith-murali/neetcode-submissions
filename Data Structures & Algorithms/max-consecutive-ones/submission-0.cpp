class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0 ;
        int n = nums.size();
        int cnt = 0;
        int max_cnt = 0;
        while(i<n){
            if(nums[i] == 1){
                cnt++;
                max_cnt = max(max_cnt, cnt);
                i++;
            }else{
                cnt = 0;
                i++;
            }
        }
        return max_cnt;
    }
};
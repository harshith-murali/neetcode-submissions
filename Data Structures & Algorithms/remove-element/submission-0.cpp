class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == val){
                nums[i] = 100000;
            }
        }
        sort(begin(nums), end(nums));
        int k=0;
        for(int i=0; i<n; i++){
            if(nums[i] != 100000){
                k++;
            }
        }
        return k;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0 , e = nums.size();
        while(s <= e){
            int mid = (e-s)/2 + s;
            if(nums[mid] == target){
                return mid;
            }else if(target > nums[mid]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return -1;
    }
};

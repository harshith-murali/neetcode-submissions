class Solution {
public:
    vector<int> getLeftMax(vector<int>& nums, int n){
        vector<int> leftMax(n);
        leftMax[0] = nums[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1] , nums[i]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int>& nums, int n){
        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1] , nums[i]);
        }
        return rightMax;
    }
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> left = getLeftMax(nums , n);
        vector<int> right = getRightMax(nums , n);

        int ans = 0;
        for(int i=0; i<n; i++){
            int area = min(left[i] , right[i]) - nums[i];
            ans += area;
        }
        return ans;
    }
};

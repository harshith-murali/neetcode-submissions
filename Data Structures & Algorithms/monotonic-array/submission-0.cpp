class Solution {
public:
    bool isInc(vector<int>& arr){
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i] > arr[i+1]) return false;
        }
        return true;
    }

    bool isDec(vector<int>& arr){
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i] < arr[i+1]) return false;
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        return isInc(nums) || isDec(nums);
    }
};
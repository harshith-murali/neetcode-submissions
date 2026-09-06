class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0 , j = n-1;
        int maxWater = 0;
        while(i < j){
            int w = j - i;
            int h = min(heights[i] , heights[j]);
            int area = w * h;
            maxWater = max(maxWater , area);

            if(heights[i] > heights[j]){
                j--;
            }else{
                i++;
            }
        }
        return maxWater;
    }
};

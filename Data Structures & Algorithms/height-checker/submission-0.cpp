class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> temp = heights;
        int cnt = 0;
        sort(temp.begin() , temp.end());
        for(int i=0; i<n; i++){
            if(temp[i] != heights[i]){
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int f(vector<int>& piles, int h){
        int totalHrs = 0;
        int n = piles.size();
        for(int i=0; i<n;i++){
            totalHrs += ceil((double)piles[i] / (double)h);
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin() , piles.end());
        while(s <= e){
            int mid = s + (e-s)/2;
            int currHrs = f(piles, mid);
            if(currHrs <= h){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return s;
    }
};

class Solution {
public:
    int f(vector<int>& piles, int maxEat){
        int totHrs = 0;
        int n = piles.size();
        for(int i=0; i<n; i++){
            totHrs += ceil((double)piles[i] / (double)maxEat);
        }
        return totHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1 , e = *max_element(begin(piles), end(piles));
        while(s <= e){
            int mid = s + (e-s)/2;
            int currHours = f(piles, mid);
            if(currHours <= h){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return s;
    }
};

class Solution {
public:
    bool find(vector<int>& weights,int capacity,int days){
        int curDays = 1 , load = 0;
        int n = weights.size();
        for(int i=0; i<n; i++){
            if(weights[i] + load > capacity){
                curDays += 1;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return curDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin() , weights.end() , 0);
        while(s <= e){
            int mid = s + (e-s)/2;
            if(find(weights,mid,days)){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return s;
    }
};
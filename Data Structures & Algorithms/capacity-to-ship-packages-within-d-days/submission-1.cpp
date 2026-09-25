class Solution {
public:
    int f(vector<int>& weights, int cap){
        int days = 1;
        int currentLoad = 0;
        int n = weights.size();
        for(int i = 0; i < n; i++){
            if(currentLoad + weights[i] > cap){
                days++;
                currentLoad = weights[i];
            } else {
                currentLoad += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(begin(weights), end(weights));
        int e = accumulate(begin(weights), end(weights), 0);
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            int currDays = f(weights, mid);
            if(currDays <= days){
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};
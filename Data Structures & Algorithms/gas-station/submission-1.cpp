class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int currGas = 0;
        int n = gas.size();
        int start = 0;
        for(int i=0; i<n; i++){
            totalGas += gas[i];
            totalCost += cost[i];
            currGas = currGas + (gas[i] - cost[i]);

            if(currGas < 0){
                currGas = 0;
                start = i+1;
            }
        }
        return totalGas < totalCost ? -1 : start;
    }
};

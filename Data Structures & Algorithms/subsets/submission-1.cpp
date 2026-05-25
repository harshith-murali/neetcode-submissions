class Solution {
public:
    void solve(int idx, vector<vector<int>>& ans, vector<int>& arr, vector<int>&ds){
        ans.push_back(ds);

        for(int i=idx; i<arr.size(); i++){
            ds.push_back(arr[i]);
            solve(i+1, ans, arr, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0 , ans, arr , ds);
        return ans;
    }
};

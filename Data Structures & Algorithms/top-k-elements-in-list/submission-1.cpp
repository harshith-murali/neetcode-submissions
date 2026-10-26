class Solution {
public:
    using pii = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(const auto& [val , freq] : mp){
            pq.push({freq, val});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

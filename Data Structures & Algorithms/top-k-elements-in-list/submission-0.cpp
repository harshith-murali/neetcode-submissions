class Solution {
   public:
   using pii = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        priority_queue<pii, vector<pii> , greater<pii>> minHeap;

        for(const auto &[val , freq]: mp){
            minHeap.push({freq, val});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};

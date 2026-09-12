class Solution {
public:
    using pii = pair<int, char>;
    
    string reorganizeString(string s) {
        int n = s.length();

        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch - 'a']++;
            // Early exit if the most frequent character exceeds the threshold
            if(freq[ch - 'a'] > (n + 1) / 2) return "";
        }

        priority_queue<pii> pq;
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(freq[ch - 'a'] > 0){
                pq.push({freq[ch - 'a'], ch});
            }
        }

        string result = "";
        
        // Process 2 characters at a time to prevent adjacent duplicates
        while(pq.size() >= 2){
            auto p1 = pq.top(); pq.pop();
            auto p2 = pq.top(); pq.pop();

            result.push_back(p1.second);
            result.push_back(p2.second);

            if(--p1.first > 0) pq.push(p1);
            if(--p2.first > 0) pq.push(p2);
        }

        // Handle the final remaining character (if any)
        if(!pq.empty()){
            result.push_back(pq.top().second);
        }

        return result;
    }
};
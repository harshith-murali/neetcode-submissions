class Solution {
public:
    string generate(string word){
        vector<int> freq(26,0);
        string res = "";
        for(char ch : word) freq[ch - 'a']++;
        for(int i=0; i<26; i++){
            int cnt = freq[i];
            if(cnt > 0){
                res += string(cnt, i + 'a');
            }
        }

        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(int i=0; i<strs.size(); i++){
            string word = strs[i];
            string parent_word = generate(word);
            mp[parent_word].push_back(word);
        }
        for(auto it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};

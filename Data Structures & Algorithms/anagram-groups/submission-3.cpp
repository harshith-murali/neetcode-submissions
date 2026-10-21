class Solution {
public:
    string generate(string &s){
        int arr[26] = {0};
        for(char ch : s) arr[ch - 'a']++;
        string parentWord = "";
        for(int i=0; i<26; i++){
            int freq = arr[i];

            if(freq > 0){
                parentWord += string(freq, i + 'a');
            }
        }
        return parentWord;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> mp;

        vector<vector<string>> res;

        for(int i=0; i<n; i++){
            string word = strs[i];

            string parentWord = generate(word);

            mp[parentWord].push_back(word);
        }

        for(auto it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> result;
    unordered_set<string> st;
    void solve(int idx, string& currSentence, string& s){
        if(idx >= s.length()){
            result.push_back(currSentence);
            return;
        }
        for(int j = idx; j < s.length(); j++){
            string tempWord = s.substr(idx , j-idx+1);
            if(st.count(tempWord)){
                string tempSentence = currSentence;
                if(!currSentence.empty()){
                    currSentence += " ";
                }
                currSentence += tempWord;
                solve(j+1, currSentence, s);
                currSentence = tempSentence;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string& word : wordDict){
            st.insert(word);
        }
        string currSentence = "";
        solve(0 , currSentence, s);
        return result;
    }
};
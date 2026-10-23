class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxLen = 0;
        int l = 0;
        for(int r = 0; r<s.length(); r++){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxLen = max(maxLen , r - l + 1);
        }

        return maxLen;
    }
};

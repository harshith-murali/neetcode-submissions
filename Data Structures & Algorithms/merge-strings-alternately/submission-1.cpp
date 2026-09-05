class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int ptr1 = 0, ptr2 = 0;
        string res = "";
        while(ptr1 < n && ptr2 < m){
            res += word1[ptr1++];
            res += word2[ptr2++];
        }
        while(ptr1 < n){
            res += word1[ptr1++];
        }
        while(ptr2 < m){
            res += word2[ptr2++];
        }
        return res;
    }
};
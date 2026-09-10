class Solution {
public:
    vector<vector<int>> dir{{1,0} , {-1,0} , {0,1}, {0,-1}};
    bool find(int i, int j, int idx, string& word, vector<vector<char>>& board, int m , int n){
        if(idx == word.length()) return true;
        if(i < 0 || j < 0 || i >= m || j >= n) return false;
        if(word[idx] != board[i][j]) return false;

        char temp = board[i][j];
        board[i][j] = '7';

        for(auto d : dir){
            int i_ = i + d[0];
            int j_ = j + d[1];
            if(find(i_, j_, idx+1, word, board, m , n)) 
                return true;
        }

        board[i][j] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0] && find(i , j , 0 , word, board , m , n)){
                    return true;
                }
            }
        }
        return false;
    }
};

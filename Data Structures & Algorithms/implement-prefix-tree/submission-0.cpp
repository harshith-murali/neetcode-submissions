class TrieNode{
    public:
        TrieNode* children[26];
        bool endOfWord;

        TrieNode(){
            for(int i=0; i<26; i++){
                children[i] = nullptr;
            }
            endOfWord = false;
        }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(crawler -> children[idx] == nullptr){
                crawler->children[idx] = new TrieNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(crawler -> children[idx] == nullptr){
                return false;
            }
            crawler = crawler->children[idx];
        }
        return crawler->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;
        for(char ch : prefix){
            int idx = ch - 'a';
            if(crawler -> children[idx] == nullptr){
                return false;
            }
            crawler = crawler->children[idx];
        }
        return true;
    }
};

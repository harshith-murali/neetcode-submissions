
class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};

class WordDictionary {
    TrieNode* root;

    bool searchHelper(string word, TrieNode* node) {
        if (word.empty()) {
            return node->endOfWord;
        }

        char ch = word[0];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr &&
                    searchHelper(word.substr(1), node->children[i])) {
                    return true;
                }
            }
            return false;
        }

        int idx = ch - 'a';

        if (node->children[idx] == nullptr) {
            return false;
        }

        return searchHelper(word.substr(1), node->children[idx]);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* crawler = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (crawler->children[idx] == nullptr) {
                crawler->children[idx] = new TrieNode();
            }

            crawler = crawler->children[idx];
        }

        crawler->endOfWord = true;
    }

    bool search(string word) {
        return searchHelper(word, root);
    }
};

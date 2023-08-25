// 208. 实现 Trie (前缀树)
#include "../def.h"

// Trie
class Trie {
public:
    static const int AB_SIZE = 26;

    struct TrieNode {
        struct TrieNode *child[AB_SIZE];
        bool isEnd;
    };
    
    struct TrieNode *root;
    Trie() {
        root = getNode();
    }

    struct TrieNode *getNode() {
        struct TrieNode* node = new TrieNode();
        for (int i=0; i<AB_SIZE; i++) {
            node->child[i] = NULL;
        }
        node->isEnd = false;
        return node;
    }
    
    void insert(string word) {
        struct TrieNode *cur = root;
        for (int i=0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if (!cur->child[index]) {
                cur->child[index] = getNode();
            }
            cur = cur->child[index];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        struct TrieNode *cur = root;
        for (int i=0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if (!cur->child[index]) {
                return false;
            }
            cur = cur->child[index];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        struct TrieNode *cur = root;
        for (int i=0; i<prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (!cur->child[index]) {
                return false;
            }
            cur = cur->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


// 官方
class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};
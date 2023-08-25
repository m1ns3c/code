// 211. 添加与搜索单词 - 数据结构设计
#include "../def.h"

class WordDictionary {
private:
    vector<WordDictionary*> child;
    bool isEnd;
public:
    WordDictionary() : child(26), isEnd(false) {
    }
    
    void addWord(string word) {
        WordDictionary *cur = this;
        for (int i=0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if (cur->child[index] == nullptr) {
                cur->child[index] = new WordDictionary();
            }
            cur = cur->child[index];
        }
        cur->isEnd = true;
    }

    bool singleMatch(WordDictionary *root, string& word, int start) {
        if (root == nullptr) {
            return false;
        }
        WordDictionary *cur = root;
        for (int i=start; i<word.size(); i++) {
            if (word[i] == '.') {
                return multiMatch(cur, word, i+1);
            }
            int index = word[i] - 'a';
            if (cur->child[index] == nullptr) {
                return false;
            }
            cur = cur->child[index];
        }
        return cur->isEnd;
    }

    bool multiMatch(WordDictionary *root, string word, int start) {
        for (int i=0; i<26; i++) {
            WordDictionary *pos = root->child[i];
            if (singleMatch(pos, word, start)) {
                return true;
            }
        }
        return false;
    }
    
    bool search(string word) {
        return singleMatch(this, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
#include "lc_header.h"
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        
    }
    bool is_leaf = false;
    map<char, TrieNode*> children;

    ~TrieNode() {
        for (auto& c: children) {
            delete c.second;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *node = root;
        for (size_t i = 0; i < word.size(); i++) {
            char c = word[i];
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            if (i == word.size() - 1) {
                node->children[c]->is_leaf = true;
            }
            node = node->children[c];
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root;
        for (char c: word) {
            if (node->children.find(c) != node->children.end()) {
                node = node->children[c];
            } else {
                return false;
            }
        }
        return node->is_leaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char c: prefix) {
            if (node->children.find(c) != node->children.end()) {
                node = node->children[c];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

int main() {
    Trie trie;
    trie.insert("abc");
    cout << trie.search("abc") << endl;
    cout << trie.search("ab") << endl;
    trie.insert("ab");
    cout << trie.startsWith("ab") << endl;
    cout << trie.startsWith("ab") << endl;
}
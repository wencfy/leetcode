#include "iostream"
#include "vector"
#include "map"
using namespace std;

class Solution {
    class TrieNode {
    public:
        map<char, TrieNode*> children;
        int pass = 0;
        int end = 0;
        TrieNode() {}
    };

    class Trie {
    public:
        TrieNode *root;

        Trie() {
            root = new TrieNode();
        }

        void insert(string s) {
            TrieNode *node = root;
            for (char c: s) {
                node->pass++;
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->pass++;
            node->end++;
        }
    };
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ret;

        Trie *trie = new Trie();
        for (string word: words) {
            trie->insert(word);
        }

        for (string word: words) {
            TrieNode *node = trie->root;
            int cnt = 0;
            for (char c: word) {
                node = node->children[c];
                cnt += node->pass;
            }
            ret.push_back(cnt);
        }
        return ret;
    }
};
/**
 * Word Break II
 * 
 * Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
 * 
 * Note that the same word in the dictionary may be reused multiple times in the segmentation.
 */

#include "iostream"
#include "vector"

#include "utils/Trie.h"
using namespace std;

class Solution {
private:
    Trie::Node *dicRoot;
    string s;
    vector<vector<string>> res = vector<vector<string>>();
    vector<string> cur = vector<string>();
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie *tree = new Trie();
        for (auto word: wordDict) {
            tree->insert(word);
        }

        dicRoot = tree->getRoot();
        this->s = s;

        dfs(0);

        vector<string> ret = vector<string>();
        for (auto l: res) {
            string line = l[0];
            for (int i = 1; i < l.size(); i++) {
                line += " " + l[i];
                // cout << str << " ";
            }
            ret.push_back(line);
        }
        return ret;
    }

    void dfs(int index) {
        Trie::Node *pointer = dicRoot;
        for (int i = index; i < s.length(); i++) {
            if (pointer->child.find(s[i]) != pointer->child.end()) {
                pointer = pointer->child[s[i]];
                if (pointer->isWord) {
                    cur.push_back(s.substr(index, i - index + 1));
                    if (i == s.length() - 1) {
                        res.push_back(cur);
                    } else {
                        dfs(i + 1);
                    }
                    cur.pop_back();
                }
            } else {
                break;
            }
        }
    }
};
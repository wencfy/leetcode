/**
 * Word Break
 * 
 * Given a string s and a dictionary of strings wordDict,
 * return true if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 */

#include "iostream"
#include "vector"
#include "string"
#include "utils/Trie.h"
using namespace std;

class Solution {
public:
    Trie::Node *root;
    string s;
    vector<int> canBeSegmented;

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie *trieTree = new Trie();
        for (string word: wordDict) {
            trieTree ->insert(word);
        }
        root = trieTree ->getRoot();
        this ->s = s;
        canBeSegmented.resize(s.length(), -1);

        return canBeSegmentedAfterIndex(0);
    }

    bool canBeSegmentedAfterIndex(int index) {
        if (canBeSegmented[index] == -1) {
            bool res = false;
            Trie::Node *pointer = root;
            
            for (int i = index; i < s.length(); i++) {
                // cout << index << " -- " << s[i] << endl;
                if (pointer ->child.find(s[i]) != pointer ->child.end()) {
                    pointer = pointer ->child[s[i]];
                    if (pointer ->isWord) {
                        if (i == s.length() - 1) {
                            res = true;
                        } else {
                            res = res || canBeSegmentedAfterIndex(i + 1);
                        }
                    }
                } else {
                    break;
                }
            }
            canBeSegmented[index] = res;
        }
        return canBeSegmented[index];
    }
};

int main() {
    string s = "catsanddog";
    vector<string> wordDict = {
        "cats",
        "dog",
        "sand",
        "and",
        "cat"
    };
    cout << (new Solution()) ->wordBreak(s, wordDict) << endl;
}
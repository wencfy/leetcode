#include "iostream"
#include "utils/Trie.h"
using namespace std;

class Solution {
    string s;
    vector<int> minExtra;
    Trie::Node *root;
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        this->s = s;
        minExtra = vector<int>(s.length(), -1);
        Trie *trie = new Trie();
        for (string str: dictionary) {
            trie->insert(str);
        }
        this->root = trie->getRoot();

        return dfs(0);
    }

    int dfs(int n) {
        if (n == s.length()) {
            return 0;
        }

        if (minExtra[n] != -1) {
            return minExtra[n];
        }

        int minCur = s.length() - n;
        Trie::Node *ptr = root;
        for (int i = n; i < s.length(); i++) {
            if (ptr->child.find(s[i]) != ptr->child.end()) {
                ptr = ptr->child.at(s[i]);
                if (ptr->isWord) {
                    minCur = min(minCur, dfs(i + 1));
                    cout << n << ": " << minCur << endl;
                }
            } else {
                break;
            }
        }
        minCur = min(minCur, 1 + dfs(n + 1));

        minExtra[n] = minCur;
        return minCur;
    }
};

int main() {
    string s = "leetscode";
    vector<string> dictionary = {"leet", "code", "leetcode"};
    (new Solution())->minExtraChar(s, dictionary);
}
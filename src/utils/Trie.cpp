#include "Trie.h"

Trie::Trie() {
    root = new Node();
}

void Trie::insert(std::string word) {
    Node *n = root;
    for (char c: word) {
        if (n ->child.find(c) == n ->child.end()) {
            n ->child[c] = new Node();
        }
        n = n ->child[c];
    }
    n ->isWord = true;
}

bool Trie::search(std::string word) {
    Node *n = root;
    for (char c: word) {
        if (n ->child.find(c) == n ->child.end()) {
            return false;
        }
        n = n ->child[c];
    }
    return n ->isWord;
}

Trie::Node *Trie::getRoot() {
    return root;
}

Trie::Node::Node() {
    isWord = false;
    child = std::map<char, Node*>();
}
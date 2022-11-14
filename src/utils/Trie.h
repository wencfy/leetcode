#include "map"
#include "string"

class Trie {
public:
    class Node {
    public:
        Node();
        ~Node();
        std::map<char, Node*> child;
        bool isWord;
    };

    Trie();
    void insert(std::string);
    bool search(std::string);
    Node *getRoot();

private:
    Node *root;
};

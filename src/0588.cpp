#include "iostream"
#include "map"
#include "sstream"
using namespace std;

class FileSystem {
    class Node {
    public:
        int type; // 0: file; 1: dir
        string name;
        string value;
        map<string, Node *> children;

        Node(int type, string name) {
            this->type = type;
            this->name = name;
        }
    };

    Node *root;
public:
    vector<string> split(string toSplit) {
        istringstream ss(toSplit);
        vector<string> tokens;

        string token;
        while (getline(ss, token, '/')) {
            tokens.push_back(token);
        }
        return tokens;
    }

    FileSystem() {
        root = new Node(1, "");
    }

    vector<string> ls(string dir) {
        vector<string> path = split(dir);
        Node *cur = root;
        for (string token: path) {
            if (token == "") {
                continue;
            } else {
                cur = cur->children[token];
            }
        }
        if (cur->type == 0) {
            return {cur->name};
        } else {
            vector<string> ret;
            for (auto p: cur->children) {
                ret.push_back(p.first);
            }
            return ret;
        }
    }

    void mkdir(string dir) {
        vector<string> path = split(dir);
        Node *cur = root;
        for (string token: path) {
            if (token == "") {
                continue;
            } else {
                if (cur->children.find(token) != cur->children.end()) {
                    cur = cur->children[token];
                } else {
                    cur->children[token] = new Node(1, token);
                    cur = cur->children[token];
                }
            }
        }
    }

    void addContentToFile(string dir, string content) {
        vector<string> path = split(dir);
        Node *cur = root;
        for (string token: path) {
            if (token == "") {
                continue;
            } else {
                if (cur->children.find(token) != cur->children.end()) {
                    cur = cur->children[token];
                } else {
                    int type = 1;
                    if (path.back() == token) {
                        type = 0;
                    }
                    cur->children[token] = new Node(type, token);
                    cur = cur->children[token];
                }
            }
        }
        cur->value = content;
    }

    string readContentFromFile(string dir) {
        vector<string> path = split(dir);
        Node *cur = root;
        for (string token: path) {
            if (token == "") {
                continue;
            } else {
                cur = cur->children[token];
            }
        }
        return cur->value;
    }
};

void print(vector<string> v) {
    cout << "[";
    for (string s: v) {
        cout << s << ", ";
    }
    cout << "]" << endl;
}

int main() {
    FileSystem* fs = new FileSystem();
    print(fs->ls("/"));
    fs->mkdir("/a/b/c");
    fs->addContentToFile("/a/b/c/d", "hello");
    print(fs->ls("/a/b/c/d"));
    cout << fs->readContentFromFile("/a/b/c/d") << endl;
}
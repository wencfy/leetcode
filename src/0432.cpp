#include "iostream"
#include "map"
#include "set"
using namespace std;

class AllOne {
public:
    class Node {
    public:
        set<string> keys;
        int cnt;
        Node *prev;
        Node *next;
        Node(set<string> keys, int cnt) {
            this->keys = keys;
            this->cnt = cnt;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    Node *head;
    Node *tail;
    map<string, Node *> kc;
    AllOne() {
        head = new Node({}, -1);
        tail = new Node({}, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if (kc.find(key) != kc.end()) {
            Node *node = kc[key];
            node->keys.erase(key);
            if (node->next == tail || node->next->cnt != node->cnt + 1) {
                Node *newNode = new Node({key}, node->cnt + 1);
                newNode->prev = node;
                newNode->next = node->next;
                newNode->prev->next = newNode;
                newNode->next->prev = newNode;
                kc[key] = newNode;
            } else {
                node->next->keys.insert(key);
                kc[key] = node->next;
            }

            if (node->keys.size() == 0) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
        } else {
            Node *firstNode = head->next;
            if (firstNode == tail || firstNode->cnt != 1) {
                Node *newNode = new Node({key}, 1);
                newNode->prev = head;
                newNode->next = firstNode;
                newNode->prev->next = newNode;
                newNode->next->prev = newNode;
                kc[key] = newNode;
            } else {
                firstNode->keys.insert(key);
                kc[key] = firstNode;
            }
        }
    }
    
    void dec(string key) {
        if (kc.find(key) == kc.end()) {
            return;
        }

        Node *node = kc[key];
        node->keys.erase(key);
        if (node->cnt == 1) {
            kc.erase(key);
        } else if (node->prev == head || node->prev->cnt != node->cnt - 1) {
            Node *newNode = new Node({key}, node->cnt - 1);
            newNode->prev = node->prev;
            newNode->next = node;
            newNode->prev->next = newNode;
            newNode->next->prev = newNode;
            kc[key] = newNode;
        } else {
            node->prev->keys.insert(key);
            kc[key] = node->prev;
        }

        if (node->keys.size() == 0) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        // for (Node *node = head; node != nullptr; node = node->next) {
        //     cout << node->cnt << endl;
        // }
    }
    
    string getMaxKey() {
        if (head->next == tail) {
            return "";
        }
        return *(tail->prev->keys.begin());
    }
    
    string getMinKey() {
        if (head->next == tail) {
            return "";
        }
        return *(head->next->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
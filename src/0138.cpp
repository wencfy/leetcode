#include "map"

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }

        std::map<Node*, Node*> mp;
        Node *ptr = head;
        Node *ret = new Node(head->val);
        Node *newPtr = ret;
        mp.insert({head, ret});
        while (ptr->next) {
            newPtr->next = new Node(ptr->next->val);
            mp.insert({ptr->next, newPtr->next});
            ptr = ptr->next;
            newPtr = newPtr->next;
        }

        ptr = head;
        newPtr = ret;
        while (ptr) {
            newPtr->random = mp[ptr->random];
            ptr = ptr->next;
            newPtr = newPtr->next;
        }
        
        return ret;
    }
};
#include "iostream"
#include "stack"
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode*> s = stack<ListNode*>();
        int i = 1;
        ListNode *lPtr = nullptr;
        ListNode *rPtr;
        for (ListNode *ptr = head; ptr; ptr = ptr->next, i++) {
            if (i < left) {
                lPtr = ptr;
            }
            if (i == right) {
                rPtr = ptr->next;
            }
            if (i >= left && i <= right) {
                s.push(ptr);
            }
        }

        if (!lPtr) {
            head = s.top();
            lPtr = head;
            s.pop();
        }

        while (!s.empty()) {
            lPtr->next = s.top();
            lPtr = lPtr->next;
            s.pop();
        }
        lPtr->next = rPtr;
        return head;
    }
};
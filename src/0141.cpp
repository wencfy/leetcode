#include "iostream"
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr) {
            fast = fast->next ? fast->next->next : fast->next;
            slow = slow->next;
            if (fast != nullptr && fast == slow) {
                return true;
            }
        }
        return false;
    }
};
#include "iostream"
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        for (ListNode *ptr = head; ptr; ptr = ptr->next) {
            cnt++;
        }

        int t = cnt / k;
        int r = cnt % k;
        vector<ListNode*> ret = vector<ListNode*>();
        ListNode *ptr = head;
        ListNode *pre;
        while (k--) {
            ret.push_back(ptr);
            for (int i = 0; i < t; i++) {
                pre = ptr;
                ptr = ptr->next;
            }
            if (r) {
                pre = ptr;
                ptr = ptr->next;
                r--;
            }
            
            if (pre) {
                pre->next = nullptr;
            }
        }
        return ret;
    }
};
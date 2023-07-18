/**
 * Add Two Numbers II
 * 
 * You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

#include "iostream"
#include "stack"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;

        for (ListNode *p = l1; p; p = p->next) {
            s1.push(p->val);
        }

        for (ListNode *p = l2; p; p = p->next) {
            s2.push(p->val);
        }

        int flag = 0;
        
        ListNode *ret = nullptr;
        while (!s1.empty() && !s2.empty()) {
            int cur = s1.top() + s2.top() + flag;
            flag = cur / 10;
            cur = cur % 10;
            s1.pop();
            s2.pop();

            ret = new ListNode(cur, ret);
        }

        while (!s1.empty()) {
            int cur = s1.top() + flag;
            flag = cur / 10;
            cur = cur % 10;
            s1.pop();

            ret = new ListNode(cur, ret);
        }

        while (!s2.empty()) {
            int cur = s2.top() + flag;
            flag = cur / 10;
            cur = cur % 10;
            s2.pop();

            ret = new ListNode(cur, ret);
        }

        while (flag) {
            int cur = flag;
            flag = cur / 10;
            ret = new ListNode(cur, ret);
        }

        return ret;
    }
};

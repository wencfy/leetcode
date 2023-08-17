/**
 * Partition List
 * 
 * Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two partitions.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include "iostream"
using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* low = nullptr;
        ListNode* high = nullptr;
        ListNode* ret = nullptr;
        ListNode* highHead = nullptr;
        for (; head != nullptr; head = head->next) {
            if (head->val < x) {
                ListNode* n = new ListNode(head->val);
                if (ret == nullptr) {
                    ret = n;
                    low = n;
                } else {
                    low->next = n;
                    low = low->next;
                }
                
            } else {
                ListNode* n = new ListNode(head->val);
                if (highHead == nullptr) {
                    highHead = n;
                    high = n;
                } else {
                    high->next = n;
                    high = high->next;
                }
            }
        }
        
        if (low) {
            low->next = highHead;
        } else {
            ret = highHead;
        }
        return ret;
    }
};

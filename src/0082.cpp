#include "iostream"
#include "vector"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// utils
ListNode* createList(vector<int> nums) {
    ListNode *cur = nullptr;
    for (int i = nums.size() - 1; i >= 0; i--) {
        cur = new ListNode(nums[i], cur);
    }
    return cur;
}
void printList(ListNode *head) {
    ListNode *cur = head;
    while (cur != nullptr) {
        cout << cur ->val << " ";
        cur = cur ->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // create head node
        ListNode *headNode = new ListNode(-1, head);
        ListNode *pre = headNode;
        ListNode *cur = head;
        while (cur != nullptr) {
            int val = cur ->val;
            ListNode *cursor = cur;
            while (cursor != nullptr) {
                if (cursor ->val == cur ->val) {
                    cursor = cursor ->next;
                } else {
                    break;
                }
            }
            // if it needs to remain one number
            // cur ->next = cursor;
            // cur = cur ->next;

            if (cur ->next != cursor) {
                pre ->next = cursor;
                cur = cursor;
            } else {
                // move pre
                pre = cur;
                // move cur
                cur = cursor;
            }
        }
        return headNode ->next;
    }
};

int main() {
    vector<int> nums = { 1, 1, 1, 2, 3, 3, 4, 5, 5 };
    ListNode *head = createList(nums);
    ListNode *res  = (new Solution()) ->deleteDuplicates(head);
    printList(res);
}
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

class Solution {
public:
    class Compare {
        public:
        bool operator()(ListNode * a, ListNode *b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, Compare> q;

        ListNode *ret = nullptr;
        ListNode *p = nullptr;

        for (auto node: lists) {
            if (node) {
                q.push(node);
            }
        }

        while (!q.empty()) {
            ListNode *node = q.top();
            q.pop();

            if (ret == nullptr) {
                ret = node;
                p = node;
            } else {
                p->next = node;
                p = p->next;
            }

            if (node->next) {
                q.push(node->next);
            }
        }

        return ret;
    }
};
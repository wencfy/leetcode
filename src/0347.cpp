/**
 * Top K Frequent Elements
 * 
 * Given an integer array nums and an integer k,
 * return the k most frequent elements. You may return the answer in any order.
 */

#include "iostream"
#include "vector"
#include "map"
using namespace std;

class Solution {
    struct NumWithCnt {
        int num;
        int count;
        
        friend bool operator>= (const NumWithCnt &lhs, const NumWithCnt &rhs) {
            return lhs.count > rhs.count;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int num: nums) {
            if (mp[num]) {
                mp[num]++;
            } else {
                mp[num] = 1;
            }
        }

        vector<NumWithCnt> heap;
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            NumWithCnt n;
            n.num = it ->first;
            n.count = it ->second;
            
            heap.push_back(n);
            int index = heap.size() - 1;
            NumWithCnt tmp = heap[index];
            while (index > 0) {
                int tar = (index - 1) / 2;
                if (heap[tar] >= tmp) {
                    break;
                } else {
                    heap[index] = heap[tar];
                    index = tar;
                }
            }
            heap[index] = tmp;

            // printf("%d -> %d\n", n.num, n.count);
            // for (NumWithCnt i: heap) {
            //     printf("%d %d\n",i.num, i.count);
            // }
            // printf("\n");
        }

        vector<int> ret;
        while (k--) {
            ret.push_back(heap[0].num);
            int index = 0;
            NumWithCnt tmp = heap.back();
            heap.pop_back();
            while (index < heap.size()) {
                int left = index * 2 + 1;
                int right = index * 2 + 2;
                if (left >= heap.size()) {
                    break;
                } else if (right >= heap.size() || heap[left] >= heap[right]) {
                    if (tmp >= heap[left]) {
                        break;
                    } else {
                        heap[index] = heap[left];
                        index = left;
                    }
                } else {
                    if (tmp >= heap[right]) {
                        break;
                    } else {
                        heap[index] = heap[right];
                        index = right;
                    }
                }
            }
            heap[index] = tmp;
        }

        return ret;
    }
};

int main() {
    vector<int> testCase = {5,-3,9,1,7,7,9,10,2,2,10,10,3,-1,3,7,-9,-1,3,3};
    vector<int> res = (new Solution())->topKFrequent(testCase, 3);
    for (int i: res) {
        printf("%d ",i);
    }
    printf("\n");
}
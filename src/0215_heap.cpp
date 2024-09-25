#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> minHeap;

    void add(int n, int maxLen) {
        if (minHeap.size() < maxLen) {
            minHeap.push_back(n);
            int idx = minHeap.size() - 1;
            int fa;
            while ((fa = (idx + 1) / 2 - 1) >= 0 && minHeap[fa] > minHeap[idx]) {
                int tmp = minHeap[idx];
                minHeap[idx] = minHeap[fa];
                minHeap[fa] = tmp;
                idx = fa;
            }
        } else {
            if (minHeap[0] < n) {
                minHeap[0] = n;
                int idx = 0;
                while (true) {
                    int lChild = (idx + 1) * 2 - 1;
                    int rChild = (idx + 1) * 2;
                    if (lChild < minHeap.size() && rChild < minHeap.size()) {
                        if (minHeap[lChild] < minHeap[rChild]) {
                            if (minHeap[idx] > minHeap[lChild]) {
                                int tmp = minHeap[lChild];
                                minHeap[lChild] = minHeap[idx];
                                minHeap[idx] = tmp;
                                idx = lChild;
                            } else {
                                break;
                            }
                        } else {
                            if (minHeap[idx] > minHeap[rChild]) {
                                int tmp = minHeap[rChild];
                                minHeap[rChild] = minHeap[idx];
                                minHeap[idx] = tmp;
                                idx = rChild;
                            } else {
                                break;
                            }
                        }
                    } else if (lChild < minHeap.size()) {
                        if (minHeap[idx] > minHeap[lChild]) {
                            int tmp = minHeap[lChild];
                            minHeap[lChild] = minHeap[idx];
                            minHeap[idx] = tmp;
                        }
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        for (auto n: minHeap) {
            cout << n << " ";
        }
        cout << endl;
    }

    int findKthLargest(vector<int>& nums, int k) {
        for (int num: nums) {
            add(num, k);
        }

        return minHeap[0];
    }
};

int main() {
    vector<int> vec = {7,6,5,4,3,2,1};
    cout << (new Solution()) ->findKthLargest(vec, 5) << endl;
}
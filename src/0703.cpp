#include "iostream"
#include "vector"
using namespace std;

class KthLargest {
private:
    int k;
    vector<int> nums;

public:
    KthLargest(int k, vector<int>& nums) {
        this ->k = k;
        for (int num: nums) {
            this ->insert(num);
        }
    }

    void insert(int num) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] == num) {
                start = mid + 1;
                end = mid;
            } else if (nums[mid] > num) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        nums.insert(nums.begin() + start, num);
    }
    
    int add(int val) {
        this ->insert(val);
        return nums[k - 1];
    }
};

int main() {
    vector<int> vec = {4, 5, 8, 2, 3};
    KthLargest *kthLargest = new KthLargest(3, vec);

    printf("%d\n", (kthLargest->add(5)));
}
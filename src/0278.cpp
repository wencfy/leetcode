#include "iostream"
using namespace std;

class Solution {
public:
    bool isBadVersion(int n) {
        return n >= 1702766719;
    }

    int firstBadVersion(int n) {
        bool flag = true;
        int low = 1;
        int high = n;
        int mid;
        while (low < high - 1) {
            mid = low + (high - low) / 2;
            bool isBad = isBadVersion(mid);
            if (isBad) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return high;
    }
};

int main() {
    cout << (new Solution())->firstBadVersion(2126753390) << endl;
    return 0;
}
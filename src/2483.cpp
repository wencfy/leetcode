#include "iostream"
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int closeCome = 0;
        for (char c: customers) {
            if (c == 'Y') {
                closeCome++;
            }
        }

        int curPanelty = closeCome;
        int curTime = 0;

        int minPanelty = closeCome;
        int minTime = 0;

        for (char c: customers) {
            curTime++;
            if (c == 'Y') {
                curPanelty--;
            } else {
                curPanelty++;
            }

            if (curPanelty < minPanelty) {
                minPanelty = curPanelty;
                minTime = curTime;
            }
        }

        return minTime;
    }
};
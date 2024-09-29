#include "iostream"
using namespace std;

class MyCalendarTwo {
public:
    vector<vector<int>> intervals;
    vector<vector<int>> doubleIntervals;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (vector<int> interval: doubleIntervals) {
            if (end > interval[0] && start < interval[1]) {
                return false;
            }
        }

        for (vector<int> interval: intervals) {
            if (end > interval[0] && start < interval[1]) {
                doubleIntervals.push_back({max(start, interval[0]), min(end, interval[1])});
            }
        }
        intervals.push_back({start, end});
        return true;
    }
};
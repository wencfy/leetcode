/**
 * Snapshot Array
 * 
 * Implement a SnapshotArray that supports the following interface:
 * 
 * SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
 * void set(index, val) sets the element at the given index to be equal to val.
 * int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
 * int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id
 */

#include "iostream"
#include "vector"
using namespace std;

class SnapshotArray {
private:
    vector<vector<pair<int, int>>> updates;
    int curSnap;
public:
    SnapshotArray(int length) {
        curSnap = 0;
        updates = vector<vector<pair<int, int>>>(length, vector<pair<int, int>>());
    }
    
    void set(int index, int val) {
        updates[index].push_back({curSnap, val});
    }
    
    int snap() {
        curSnap++;
        return curSnap - 1;
    }
    
    int get(int index, int snap_id) {
        int idx = upper_bound(updates[index].begin(), updates[index].end(), make_pair(snap_id,INT_MAX)) - updates[index].begin();
        if (idx == 0) return 0;
        return updates[index][idx - 1].second;
    }
};

// TLE
// class SnapshotArray {
// private:
//     vector<vector<int>> snapshots;
//     vector<int> arr;
// public:
//     SnapshotArray(int length) {
//         arr = vector<int>(length);
//     }
    
//     void set(int index, int val) {
//         arr[index] = val;
//     }
    
//     int snap() {
//         snapshots.push_back(arr);
//         return snapshots.size() - 1;
//     }
    
//     int get(int index, int snap_id) {
//         return snapshots[snap_id][index];
//     }
// };
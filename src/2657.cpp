#include "iostream"
#include "map"
using namespace std;


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int, int> mpA;
        map<int, int> mpB;

        vector<int> ret;

        for (int i = 0; i < A.size(); i++) {
            int prev;
            if (i == 0) {
                prev = 0;
            } else {
                prev = ret[i - 1];
            }

            if (mpA.find(A[i]) == mpA.end()) {
                mpA[A[i]] = 1;
            } else {
                mpA[A[i]]++;
            }
            if (mpB[A[i]] && mpB[A[i]] >= mpA[A[i]]) {
                prev += 1;
            }

            if (mpB.find(B[i]) == mpB.end()) {
                mpB[B[i]] = 1;
            } else {
                mpB[B[i]]++;
            }

            if (mpA[B[i]] && mpA[B[i]] >= mpB[B[i]]) {
                prev += 1;
            }

            ret.push_back(prev);
        }

        return ret;
    }
};
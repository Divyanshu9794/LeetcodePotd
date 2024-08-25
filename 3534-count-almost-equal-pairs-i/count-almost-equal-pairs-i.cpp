#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canDigitsBeSwapped(int idxA, int idxB, vector<int>& numArray) {
        string numStrA = to_string(numArray[idxA]);
        string numStrB = to_string(numArray[idxB]);

        while (numStrA.length() < numStrB.length()) numStrA = '0' + numStrA;
        while (numStrB.length() < numStrA.length()) numStrB = '0' + numStrB;

        if (numStrA == numStrB) {
            return true;
        }

        vector<int> differingIndices;
        for (int pos = 0; pos < numStrA.size(); ++pos) {
            if (numStrA[pos] != numStrB[pos]) {
                differingIndices.push_back(pos);
            }
        }

        if (differingIndices.size() == 2) {
            swap(numStrA[differingIndices[0]], numStrA[differingIndices[1]]);
            if (numStrA == numStrB) {
                return true;
            }
        }

        return false;
    }

    int countPairs(vector<int>& numArray) {
        int totalNums = numArray.size();
        int almostEqualPairs = 0;
        for (int outerIdx = 0; outerIdx < totalNums; outerIdx++) {
            for (int innerIdx = outerIdx + 1; innerIdx < totalNums; innerIdx++) {
                if (canDigitsBeSwapped(outerIdx, innerIdx, numArray)) {
                    almostEqualPairs++;
                }
            }
        }
        return almostEqualPairs;
    }
};

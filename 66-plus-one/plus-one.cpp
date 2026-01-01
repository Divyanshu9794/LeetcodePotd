class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    vector<int> leadingOne = { 1 };
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            if (*it != 9) {
                ++*it;
                return digits;
            } else
                *it = 0;
        }
        leadingOne.insert(leadingOne.end(), digits.begin(), digits.end());
        return leadingOne;
    }
    
};
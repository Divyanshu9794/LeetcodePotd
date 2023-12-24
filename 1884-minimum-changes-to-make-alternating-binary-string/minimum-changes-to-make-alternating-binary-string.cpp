class Solution {
public:
    int minOperations(string s) {
        int a = 0;
        int b = 0;
        int sz = s.size();
        for(int i = 0 ; i < sz ; i++){
            a += ((i % 2 == 0 and s[i] == '1') or (i % 2 != 0 and s[i] == '0'));
            b += ((i % 2 == 0 and s[i] == '0') or (i % 2 != 0 and s[i] == '1'));
        }
        return min(a, b);
    }
};
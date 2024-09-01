class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.length();
        int numSubstrings = n / k;
        string result = "";
        
        for (int i = 0; i < numSubstrings; ++i) {
            int sum = 0;
            for (int j = 0; j < k; ++j) {
                sum += s[i * k + j] - 'a';
            }
            int hashedChar = sum % 26;
            result += (char)('a' + hashedChar);
        }
        
        return result;
    }
};

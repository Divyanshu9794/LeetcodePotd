class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, close = 0;
        string ans;
        for (const char& c : s) {
            if (c != '(' && c != ')') {
                ans += c;
            } else if (c == '(') {
                open++;
                ans += c;
            } else if (open > 0) {
                ans += c;
                open--;
            }
        }

       
        if (open > 0) {
             int n = ans.length();
            s = ans;
            ans = "";
            open = 0, close = 0;
            for (int i = n - 1; i >= 0; i--) {
                char c = s[i];
                if (c != '(' && c != ')') {
                    ans += c;
                } else if (c == ')') {
                    close++;
                    ans += c;
                } else if (close > 0) {
                    ans += c;
                    close--;
                }
            }
        }
        else{
            return ans;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for (char x : s) {
            num += to_string(x - 'a' + 1);
        }
        
        while (k > 0) {
            int t = 0;
            for (char x : num) {
                t += x - '0'; 
            }
            num = to_string(t); 
            k--;
        }
        return stoi(num);
    }
};
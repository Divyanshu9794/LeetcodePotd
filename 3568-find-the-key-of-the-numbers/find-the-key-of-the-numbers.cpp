class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string str1 = padWithZeros(num1);
        string str2 = padWithZeros(num2);
        string str3 = padWithZeros(num3);
        string key = "";
        for (int i = 0; i < 4; ++i) {
            char minDigit = std::min({str1[i], str2[i], str3[i]});
            key += minDigit;
        }
        return stoi(key);
    }
    string padWithZeros(int num) {
        string str = to_string(num);
        while (str.length() < 4) {
            str = "0" + str;
        }
        return str;
    }
};
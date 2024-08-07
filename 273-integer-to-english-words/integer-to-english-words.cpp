class Solution {
public:
    map<int, string> d = {
        {0, "Zero"},     {1, "One"},        {2, "Two"},       {3, "Three"},
        {4, "Four"},     {5, "Five"},       {6, "Six"},       {7, "Seven"},
        {8, "Eight"},    {9, "Nine"},       {10, "Ten"},      {11, "Eleven"},
        {12, "Twelve"},  {13, "Thirteen"},  {14, "Fourteen"}, {15, "Fifteen"},
        {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
        {20, "Twenty"},  {30, "Thirty"},    {40, "Forty"},    {50, "Fifty"},
        {60, "Sixty"},   {70, "Seventy"},   {80, "Eighty"},   {90, "Ninety"}};

    long long countDigit(long long num) {
        if (num == 0)
            return 1;
        return floor(log10(num) + 1);
    }

    string lessThanThousand(int num) {
        if (num == 0)
            return "";
        int n = countDigit(num);
        if (num < 20) {
            return d[num];
        } else if (n == 2) {
            int a = num % 10;
            int b = (num / 10) * 10;
            string ans;
            ans = a == 0 ? d[b] : d[b] + " " + d[a];
            return ans;
        } else {
            int temp = num / 100;
            string ans = d[temp] + " Hundred";
            if (num % 100 != 0) {
                ans += " " + lessThanThousand(num % 100);
            }
            return ans;
        }
    }

    string numberToWords1(int num) {
        int n = countDigit(num);
        if (n <= 3) {
            return lessThanThousand(num);
        } else if (n <= 6) {
            int temp = num / 1000;
            string ans = lessThanThousand(temp) + " Thousand";
            if (num % 1000 != 0) {
                ans += " " + lessThanThousand(num % 1000);
            }
            return ans;
        } else if (n <= 9) {
            int temp = num / 1000000;
            string ans = lessThanThousand(temp) + " Million";
            if (num % 1000000 != 0) {
                ans += " " + numberToWords1(num % 1000000);
            }
            return ans;
        } else {
            int temp = num / 1000000000;
            string ans = lessThanThousand(temp) + " Billion";
            if (num % 1000000000 != 0) {
                ans += " " + numberToWords1(num % 1000000000);
            }
            return ans;
        }
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        } else {
            string ans = numberToWords1(num);
            return ans;
        }
    }
};
class Solution {
public:
    int maxScore(const  string& s) {
        int max_score = 0;
        int cl = 0;
        int cr =  count(s.begin(), s.end(), '1');

        for (int i = 0; i < s.size() - 1; ++i) {
            cl += (s[i] == '0');
            cr -= (s[i] == '1');
            max_score =  max(max_score, cl + cr);
        }

        return max_score;
    }
};
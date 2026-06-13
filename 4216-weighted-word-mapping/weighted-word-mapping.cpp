class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        res.reserve(words.size());
        for (string word : words) {
            int s = 0;
            for (char c : word) {
                s += weights[c - 'a'];
            }
            res += 'z' - s % 26;
        }
        return res;
    }
};
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<int> s={sentence.begin(),sentence.end()};
        return s.size()==26;
    }
};

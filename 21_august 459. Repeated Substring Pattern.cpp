class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string tmp=s+s;
        if(tmp.substr(1,tmp.size()-2).find(s)==-1) return false;
        return true;
        
    }
};

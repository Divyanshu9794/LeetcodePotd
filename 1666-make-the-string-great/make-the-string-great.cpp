class Solution {
public:
    string makeGood(string s) 
    {
        string ans;
        ans += s[0];
        int n = s.size();
        for(int i=1;i<n;i++)
        {
            if(!ans.empty() and isupper(s[i]) and islower(ans.back()) and s[i]==toupper(ans.back()))
                ans.pop_back();
            else if(!ans.empty() and islower(s[i]) and isupper(ans.back()) and s[i]==tolower(ans.back()))
                ans.pop_back();
            else ans += s[i];
        }
        return ans;
    }
};
class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> m;
        char start = 'a';
        for(auto ch:key){
            if(ch!=' '&& m[ch]==0){
                m[ch]=start;
                start++;
            }
        }
        string ans;
        for(auto ch:message){
            if(ch==' '){
                ans.push_back(ch);
            }
            else{
                ans.push_back(m[ch]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string s ;
        int n = words.size();
        for(int i=0;i<n;i++){
            s= words[i];
            string t;
            t=s;
            reverse(t.begin(),t.end());
            if(t==s){
                return s;
            }
        }
        return "";
        
    }
};
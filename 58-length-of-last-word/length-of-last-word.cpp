class Solution {
public:
    int lengthOfLastWord(string s) {
       int ans = 0;
        reverse(s.begin(),s.end());
        bool spc = false;  
        for(int i=0;s[i];i++){
            
            if(s[i] == ' ' && spc){
                break;
            }
            if(s[i] == ' ' && !spc){
            }
            else{
                spc = true;
                ans++;
            }
        }
        return ans;
    }
};
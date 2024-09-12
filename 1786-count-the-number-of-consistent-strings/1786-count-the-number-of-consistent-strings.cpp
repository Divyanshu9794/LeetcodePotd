class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>st(allowed.begin(),allowed.end());
        int f=0;
        int c=0;
        for(auto it:words){
            f=0;
            for(auto ch:it){
                if(st.find(ch)==st.end()){
                    f=1;
                    break;
                }
            }
            if(f==0){
                c++;
            }
        }
        return c;
        
    }
};

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string r1 = "qwertyuiopQWERTYUIOP";
        string r2 = "asdfghjklASDFGHJKL";
        string r3 = "zxcvbnmZXCVBNM";
        unordered_map<char,int> mp1,mp2,mp3;
        vector<string> ans;

        for(auto x:r1){
            mp1[x]++;
        }
        for(auto x:r2){
            mp2[x]++;
        }
        for(auto x:r3){
            mp3[x]++;
        }
        for(auto x:words){
            string ans1 ="",ans2 ="",ans3="";
            for(int i=0;i<x.size();i++){
                if(mp1.find(x[i])!= mp1.end()){
                    ans1+=x[i];
                }
                else if(mp2.find(x[i])!= mp2.end()){
                    ans2+=x[i];
                }
                else if(mp3.find(x[i])!= mp3.end()){
                    ans3+=x[i];
                }
            }

            if(ans1==x){
                ans.push_back(x);
            }
            if(ans2==x){
                ans.push_back(x);
            }
            if(ans3==x){
                ans.push_back(x);
            }

        }
        return ans;

        
    }
};
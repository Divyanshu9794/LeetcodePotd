class Solution {
public:
    vector<int> dp;
    int numDecodings(string s) {
        dp.resize(s.size());
        dp.assign(s.size(),-1);

        return nway(0,s);
    }
   int nway(int i , string s){
        if(i>=s.size()){
            return 1;

        }
        else if(s[i]=='0'){
            return 0;
        }
        else if(i==s.size()-1){
            return 1;
        }
        else if(dp[i]!=-1){
            return dp[i];
        }
        else if(s[i]=='1' || (s[i]=='2' && (s[i+1]>=48 && s[i+1]<=54)) ){
            return dp[i]= nway(i+1,s)+nway(i+2,s);

        }
        else{
            return dp[i]= nway(i+1,s);
        }

    }
};
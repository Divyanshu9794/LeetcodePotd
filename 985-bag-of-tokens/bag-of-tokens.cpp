class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans=0,res=0;
        int i=0,j=tokens.size()-1;
        
        sort(tokens.begin(),tokens.end());
        
        while(i<=j){
            if(power>=tokens[i]){
                ans++;
                power-=tokens[i];
                i++;
            }
            
            else{
               if(ans<1)break;
                ans--;
                power+=tokens[j];
                j--;
            }
            res=max(res,ans);
        }
        
        return res;
    }
};
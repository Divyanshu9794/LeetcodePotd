class Solution {
public:
    int findLength(vector<int>& s1, vector<int>& s2) {
        int x=s1.size();
//calculating Size of first vector s1
        int y=s2.size();
//calculating Size of 2nd vector s2
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
//a 2d vector of size x+1 and y+1 
        for(int j=0;j<=y;j++){
            dp[0][j]=0;
//storing value 0 for 1st row
            
        }
        for(int i=0;i<=x;i++){
            dp[i][0]=0;
            
        }
//storing value 0 for 1st column
        
        int ans = 0;
//a answer variable initial value set to 0
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
//if vectors consecutive element are matched the adding 1 to previous //diagonally stored value
                    dp[i][j]=1+dp[i-1][j-1];

                    ans=max(ans,dp[i][j]);
//storing maximum value to ans variable
                }
                else{
                    dp[i][j]=0;
// if element not matched then store 0 at that index
                }
            }
        }
        return ans;
// at last return 0
    }
    
};


//if helpful please upvote the solution
//by divyanshu singh....😌

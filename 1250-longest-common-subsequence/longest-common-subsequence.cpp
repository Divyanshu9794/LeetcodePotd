class Solution {
public:

    // int f(int i,int j,string &text1,string &text2,vector<vector<int>> &dp){
    //     if(i==0 || j==0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(text1[i-1]==text2[j-1]){
    //         return dp[i][j]=1+f(i-1,j-1,text1,text2,dp);
    //     }
    //     return dp[i][j]=max(f(i-1,j,text1,text2,dp),f(i,j-1,text1,text2,dp));

    // }
   
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    int f(int i,int j,string &s1,string &s2, vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j] = 1 + f(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j] = max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    
    int longestCommonSubsequence( string s1, string s2)
    {
        
        int x= s1.length();
        int y= s2.length();
        vector<vector<int>> dp(x,vector<int>(y,-1));
        // your code here
        return f(x-1,y-1,s1,s2,dp);
    }
};
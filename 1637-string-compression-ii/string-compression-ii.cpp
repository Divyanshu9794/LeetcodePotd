class Solution {
public:
    
    int getLength(int count){
        if(count==1)return 1; 
        else{
            if(count<10)return 2; 
            else{
                if(count<100)return 3; 
                else return 4;  
            }
        }
    }
    int getLengthOfOptimalCompression(string s, int k) {   
        int n = s.size();
        int dp[n+1][k+1];
        for(int i=n;i>=0;i--){
            for(int j=0;j<=k;j++){
                if(i == n) { dp[n][j] = 0;  continue;}
                dp[i][j] = j>0 ? dp[i+1][j-1]:INT_MAX;
                int possible_del = j,count=0;
                for(int end =i;end<n&&possible_del>=0 ;end++){
                    if(s[end] == s[i]){
                        count++;
                        dp[i][j] = min(dp[i][j] , getLength(count)+dp[end+1][possible_del]);
                    }
                    else { 
                        possible_del--;
                    }
                }
            }
        }
        return dp[0][k];
    }
};
class Solution {
public:
     long long m = 1e9 + 7;
    int func(int n , int num , int x , vector<vector<int>> &dp)
          {
            if(n < 0 )
               return 0 ;
                
            if(n == 0)
               {
                  return 1 ;
                }
                
              if(pow(num , x) > n)
                return 0 ;
                
            if(dp[n][num] != -1)
              return dp[n][num] ;
          
            int temp = pow(num , x) ;
            
            int case1 = func(n- temp , num + 1 , x , dp );
            int case2 = func(n , num + 1 , x , dp);
            
            return dp[n][num] =  (case1%m + case2%m )%m ;
          }
          

    
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1 , vector<int>(n +1, -1)) ;
        
        return func(n , 1 ,  x , dp) ;
    }
};

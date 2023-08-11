class Solution {
public:
    int change(int a, vector<int>& coins) {
         int n=coins.size();
        int t[n+1][a+1];
        for(int i=0;i<=n;i++){
            t[i][0]=1;
        }
        for(int i=1;i<=a;i++){
            t[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a;j++){
                if(coins[i-1]<=j){
                    t[i][j]=t[i-1][j] + t[i][j-coins[i-1]];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
  
            }
        }
        return t[n][a];
   
    }
};

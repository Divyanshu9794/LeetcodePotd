class Solution {
public:
    int superEggDrop(int k, int n) {
        int dp[n+1][k+1];
       
        for(int i=1;i<=k;i++){
            dp[0][i]=0;
            dp[1][i]=1;
        }
        for(int i=1;i<=n;i++){
            dp[i][1]=i;
            dp[i][0]=INT_MAX;
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){

                int low=1,high=i,temp=0,ans=INT_MAX;
                while(low<=high){
                    int mid=(low+high)/2;
                    int left=dp[mid-1][j-1];
                    int right=dp[i-mid][j];
                    temp=1+max(left,right);
                    if(left<right)low=mid+1;
                    else
                    high=mid-1;
                    ans=min(ans,temp);
                }
                dp[i][j]=ans;
            }
        }
        return dp[n][k];
    }
};

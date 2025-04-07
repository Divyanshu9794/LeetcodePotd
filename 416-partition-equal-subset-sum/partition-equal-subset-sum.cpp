class Solution {
public:
bool solve(int index,vector<int>&arr,int n,int target)
{
   vector<int>curr(target+1,0);
    vector<int>next(target+1,0);
    //base case
      curr[0]=1;
      next[0]=1;

    for(int i=n-1;i>=0;i--)
    {
        for(int t=0;t<=target;t++)
        {
        bool include=0;
      if(t-arr[i]>=0) 
    include=next[t-arr[i]];
    bool exclude=next[t];
    
      curr[t]=include or exclude;
        }
        next=curr;
    }
  return curr[target];
}
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
            int total=0;
            for(int i=0;i<n;i++)
            {
                total=total+arr[i];
            }
            if(total & 1)
            {
                return 0;
            }
        int target=total/2;
        
        return solve(0,arr,n,target);
        
    }
};
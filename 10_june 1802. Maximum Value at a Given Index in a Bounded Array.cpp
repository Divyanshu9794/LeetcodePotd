class Solution {
private:
    bool check(long long val,int index, int n, int m){
        long long left = index+1,leftsum = 0;
        long long right = n-index-1,rightsum = 0;
        if(left<val) leftsum = left*val - left*(left-1)/2;
        else leftsum = val*(val+1)/2 + (left-val);
        if(right<val) rightsum = right*val - right*(right+1)/2;
        else rightsum = val*(val-1)/2 + (right-val+1);
        return (leftsum+rightsum) <= m;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        long long lo = 1, hi = maxSum, mid = 0,ans = 0;
        while(lo <= hi){
            mid = (hi+lo)>>1LL;
            if(check(mid,index,n,maxSum)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};

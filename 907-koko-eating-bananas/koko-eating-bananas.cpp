class Solution {
public:

    int findmax(vector<int> &piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    long long fun(vector<int> &piles,int hours){
        int n = piles.size();
        long long total=0;
        for(int i=0;i<n;i++){
            total += ceil((double)piles[i]/(double)hours);

        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int low=1,high= findmax(piles);
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            long long totalhrs = fun(piles,mid);
            if(totalhrs<=h){
                ans=mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
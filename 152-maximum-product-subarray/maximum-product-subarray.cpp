class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN,suf =1,pre=1,n = nums.size();

        for(int i=0;i<=n-1;i++){
            if(pre==0){
                pre=1;
            }
            if(suf==0){
                suf=1;
            }
            pre = pre * nums[i];
            suf = suf *  nums[n-i-1]; // this will calculate product from back
            maxi = max({maxi,pre,suf});
        }
        return maxi;
        
    }
};
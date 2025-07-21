class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int> ans(n,0);
        int zero =0,ind =-1,prod =1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
                ind = i;
            }
            else{
                prod *= nums[i];
            }
        }
        if(zero==0){
            for(int i=0;i<n;i++){
                ans[i]=prod/nums[i];
            }
        }
        else if(zero==1){
            ans[ind]=prod;
        }
        return ans ;
    }
};
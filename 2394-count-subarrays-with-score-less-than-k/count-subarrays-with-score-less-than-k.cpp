class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0,res =0;
        for(int i=0,j=0;j<n;j++){
            res += nums[j];
            while(i<=j && res*(j-i+1)>=k){
                res -= nums[i];
                i++;
            }
            ans += j-i+1;
        }
        return ans;
    }
};
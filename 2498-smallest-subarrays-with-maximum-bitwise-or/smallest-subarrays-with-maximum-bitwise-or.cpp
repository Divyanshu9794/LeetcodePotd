class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> closest(32);
        for(int i=n-1;i>=0;i--){
            int mx=i;
            for(int j=0;j<32;j++){
                if(nums[i]&(1<<j)){ // if bit is set
                    closest[j] =i;
                }
                else{
                    mx = max(mx,closest[j]);
                }
            }
            ans[i] = mx -i+1;
        }
        return ans;
    }
};
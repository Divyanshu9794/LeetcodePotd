class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<vector<int>> closest(n,vector<int>(32,-1));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<32;j++){
                if(nums[i]&(1<<j)){ // if bit is set
                    closest[i][j] =i;
                }
                else{
                    if(i<n-1){
                        closest[i][j]= closest[i+1][j];
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            int mx =i;
            for(int j=0;j<32;j++){
                mx= max(mx,closest[i][j]);
            }
            ans[i] = mx -i+1;
        }
        return ans;
        
    }
};
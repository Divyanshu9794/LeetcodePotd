class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans(2);
        int len=nums.size();
        vector<int>hash(len,0);
        for(int i=0;i<len;i++){
            hash[nums[i]-1]++;
        }
        for(int i=0;i<len;i++){
            if(hash[i]==0){
                ans[1]=i+1;
            }
            if(hash[i]==2){
                ans[0]=i+1;
            }
        }
        return ans;
    }
};
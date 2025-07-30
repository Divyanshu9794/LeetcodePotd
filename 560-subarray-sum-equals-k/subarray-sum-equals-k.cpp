class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         unordered_map<int,int> mp;
        int curr=0,ans=0;
        mp[0]=1;
        for(int i:nums){
            curr+=i;
            ans+= mp[curr-k];
            mp[curr] ++;
        }
        return ans;
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // int n = nums.size();
        // for(int x:nums){
        //     mp[x]++;
        //     if(mp[x]>1){
        //         return true;
        //     }

        // }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
        
        
    }
};
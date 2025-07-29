class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans ;
        map<int,int> mp;
        int mini = (int)(n/3) + 1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==mini){
                ans.push_back(nums[i]);
            }
            if(ans.size()==2){
                return ans;
            }
        }
        return ans;
    }
};
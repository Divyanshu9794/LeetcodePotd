class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans ;
        map<int,int> mp;
        int n = nums.size();
        int mini = (int)n/3 + 1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==mini){
                ans.push_back(nums[i]);
            }
            if(ans.size()==2) break;
        }
        sort(ans.begin(),ans.end());
        return ans ;
    }
};
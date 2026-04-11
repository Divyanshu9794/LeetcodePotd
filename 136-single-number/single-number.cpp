class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto x: mp){
            if(x.second==1){
                return x.first;
            }
        }
        return 0;
    }
};
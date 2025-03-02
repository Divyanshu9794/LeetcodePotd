class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;
        for(auto num:nums1){
            mp[num[0]]=num[1];
        }
        for(auto num:nums2){
            mp[num[0]]+=num[1];
        }
        vector<vector<int>> sums;
        for(auto i:mp){
            sums.push_back({i.first,i.second});
        }
        return sums;
        
    }
};
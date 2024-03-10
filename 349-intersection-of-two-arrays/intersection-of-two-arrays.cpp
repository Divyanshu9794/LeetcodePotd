class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         set<int>res;
        vector<int>sol;
        for(int i:nums1){
            for(int j:nums2){
                if(i==j)
                res.insert(i);
            }
        }
        for(int i:res){
            sol.push_back(i);
        }
        return sol;
    }
};
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x]++;
        }

        int sum =0;
        for(auto a: mp){
            if(a.second == 1){
                sum+=a.first;
            }
        }

        return sum;
        
    }
};
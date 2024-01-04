class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int c=0;
        for(auto &a:mp){
            if(a.second==1){
                return -1;
            }
            int b=a.second/3;
            c+=b;
            if(a.second%3){
                c++;
            }
        }
        return c;

        
    }
};
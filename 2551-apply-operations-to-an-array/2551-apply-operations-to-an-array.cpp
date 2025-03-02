class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n= nums.size();
        vector<int> a;
        

        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1] && nums[i]!=0){
                nums[i] *= 2;
                nums[i+1]=0;
            }
        }
        for(int c:nums){
            if(c!=0){
                a.push_back(c);
            }
        }
        while(a.size()<n){
            a.push_back(0);
        }
        return a ;
    }
};
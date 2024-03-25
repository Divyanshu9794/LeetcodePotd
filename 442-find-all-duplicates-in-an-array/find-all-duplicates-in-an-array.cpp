class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int > ans;
        sort(nums.begin(),nums.end());
        int a;
       for(int i=0;i<n-1;i++){
         
               if(nums[i]==nums[i+1]){
                   ans.push_back(nums[i]);
                   i=i+1;
               }
           }
       
      return ans;
    }
    
};
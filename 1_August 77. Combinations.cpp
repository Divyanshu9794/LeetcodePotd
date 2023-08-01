class Solution {
public:
    void helper(vector<int>& nums, int k, int index, vector<int>& temp, vector<vector<int>>& ans){

        
            if(k==0){
                ans.push_back(temp);
                return;
            }
          

            if(index==nums.size()) return ;

            for(int i = index;i<nums.size();i++){
                temp.push_back(nums[i]);
                helper(nums,k-1,i+1,temp,ans);
                temp.pop_back();
            }



    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> nums;

        for(int i = 1;i<=n;i++){
            nums.push_back(i);
        }

        helper(nums,k,0,temp,ans);
        return ans;
    }
};

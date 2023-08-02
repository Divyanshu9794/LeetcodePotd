class Solution {
public:
    void s(vector<int> nums, vector<vector<int>>& ans,int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            s(nums,ans,index+1);
            swap(nums[index],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
         int index=0;
         s(nums,ans,index);
         return ans;

    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        int res=1;
        for(int i=1;i<l;i++)
        {
            if(nums[i]!=nums[res-1])
            {
                nums[res]=nums[i];
                res++;
            }
        }
        return res;

        
    }
};
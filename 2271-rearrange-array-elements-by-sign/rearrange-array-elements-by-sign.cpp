class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n,0);
        int temp=0,flag=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                v[temp]=nums[i];
                temp=temp+2;
            }
            else
            {
                v[flag]=nums[i];
                flag=flag+2;
            }
        }
        return v;
    }
};
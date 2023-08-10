class Solution {
public:
    bool search(vector<int>& nums, int target) {
           int n=nums.size();
        int  count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target)
            {
                return true;
            }
            else{
                count++;
            }
        }
        if(count==n){
            return false;
        }
        return -false;
        
    }
};

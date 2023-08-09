class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int  count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target)
            {
                return i;
            }
            else{
                count++;
            }
        }
        if(count==n){
            return -1;
        }
        return -1;

        
    }
};

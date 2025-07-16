class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c=0;
        for(int n:nums){
            if(n!=val){
                nums[c++]=n;
            }
        }
        
        return c;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int l = nums.size();
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        if((k-1)<0){
            return nums[0];
        }
        return nums[k-1];
    }
};
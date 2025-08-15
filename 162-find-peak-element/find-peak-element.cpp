class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        int lo =1,hi = n-2;
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){
                lo=mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return -1;
    }

};
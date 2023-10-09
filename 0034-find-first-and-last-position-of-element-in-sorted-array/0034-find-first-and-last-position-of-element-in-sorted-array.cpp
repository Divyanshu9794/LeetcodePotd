class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int l = 0;
        int r = nums.size() - 1;
        int mid;
        int start = -1;
        int end = -1;
        vector<int> result;
        
      
        while(l <= r)
        {
            mid = (l + r) / 2;
            if(nums[mid] == target)
            {
                start = end = mid; 
            }
            if(nums[mid] > target){r = mid - 1;}
            else{l = mid + 1;}
        }
        
      
        while(start > 0 && nums[start - 1] == target)
        {
             --start;
        }
        while(end < nums.size() - 1 && nums[end + 1] == target){ ++end;} 
        
        result.push_back(start);
        result.push_back(end);
        
        return result;
      
    }
    
};
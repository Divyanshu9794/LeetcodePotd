class Solution {
public:
    int specialArray(vector<int>& nums) {
        int i = 1, j = nums.size();
		while(i <= j)
        {
			int mid = i + (j - i)/2, count=0;
			for(int k = 0; k < nums.size(); k++)
            {
				if(nums[k] >= mid)
                count++;		
            }	
			if(count==mid)
            return mid;
			else if(count<mid)
            j = mid - 1;
			else
            i = mid + 1;
		}
		return -1;
	
    }
};
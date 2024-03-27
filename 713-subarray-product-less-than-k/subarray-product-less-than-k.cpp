#define ll long long

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k<=1)
            return 0;

        int n = nums.size(), curr = -1, res=0, pr;
        vector<int> next(n,-1);

        for(int i=n-1; i>=0; --i)
        {
            if(nums[i]!=1)
                curr = i;
            else
                next[i] = curr;
        }

        for(int i=0; i<n; ++i)
        {
            pr = 1;
            bool stat = true;

            for(int j=i; j<n; )
            {
                if(nums[j] == 1)
                {
                    j = next[j];

                    if(j == -1)
                    {
                        stat = false;
                        res+=n-i;
                        break;
                    }
                }

                else
                {
                    pr*=nums[j];
                    ++j;
                }

                if(pr >= k)
                {
                    res+=j-i-1;
                    stat = false;
                    break;
                }
            }

            if(stat)
                res+=n-i;
        }
        
        return res;
    }
};
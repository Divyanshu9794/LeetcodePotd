class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc=true;
    bool dec=true;

    if (nums.size() == 1)
        return true;
    else
    {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] > nums[i + 1])
                    inc=false;
            }
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] < nums[i + 1])
                    dec=false;
            }
    }
    return (inc || dec);
    }
};
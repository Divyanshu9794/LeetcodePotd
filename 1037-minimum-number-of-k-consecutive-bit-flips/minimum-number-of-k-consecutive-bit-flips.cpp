class Solution {
public:
     int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int j = 0; 
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                if (nums[i - k] == 2) {
                    j ^= 1;
                }
            }
            if ((nums[i] ^ j) == 0) {
                if (i + k > n) {
                    return -1;
                }
                flips++;
                j ^= 1; 
                nums[i] = 2;  
            }
        }

        return flips;
    }
};
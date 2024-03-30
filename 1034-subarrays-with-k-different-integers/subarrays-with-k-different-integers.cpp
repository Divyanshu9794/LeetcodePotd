class Solution {
public:
    int calc(vector<int>& nums, int k) {
        int res = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        while (i < n) {
            mp[nums[i]]++;
            while (j <= i && mp.size() > k) {
                if(--mp[nums[j]] == 0) mp.erase(nums[j]);
                j++;
            }
            res += (i - j + 1);
            i++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return calc(nums,k)-calc(nums,k-1);
    }
};
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        int allXor = 0;
        for(auto& num : nums) allXor ^= num;

        vector<int> res;

        int num = ((1 << maximumBit) - 1);

        for(int i = n-1; i >= 0; --i){
            int temp = (allXor ^ ((1 << maximumBit) - 1));

            res.push_back(temp);

            allXor ^= nums[i];
        }

        return res;
    }
};
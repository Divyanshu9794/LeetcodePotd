class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(2,0),same(2,0);
        for(int i=0;i<n;i++){
            int current_remainder = nums[i]%2;
            same[current_remainder] = 1+ same[current_remainder];
            diff[current_remainder] = max(diff[current_remainder], 1+ diff[1^current_remainder]);
        }
        return max({same[0],same[1],diff[0],diff[1]});
        
    }
};
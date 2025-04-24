class Solution {
public:


    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        int k = set.size();
        unordered_map<int, int> map;
        int count = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            map[nums[j]]++;
            while (map.size() == k) {
                count += n - j;
                map[nums[i]]--;
                if (map[nums[i]] == 0) {
                    map.erase(nums[i]);
                }
                i++;
            }
        }
        return count;
 
    }
};
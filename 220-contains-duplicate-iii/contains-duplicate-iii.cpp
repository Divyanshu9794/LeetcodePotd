class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0) return false;  

        unordered_map<long long, long long> buckets;
        long long size = (long long)valueDiff + 1;

        for (int i = 0; i < nums.size(); ++i) {
            long long num = (long long)nums[i];
            long long bucketId = num / size;
            if (num < 0) bucketId--; 
            if (buckets.count(bucketId)) return true;

            if (buckets.count(bucketId - 1) && abs(num - buckets[bucketId - 1]) <= valueDiff)
                return true;
            if (buckets.count(bucketId + 1) && abs(num - buckets[bucketId + 1]) <= valueDiff)
                return true;

            buckets[bucketId] = num;

            if (i >= indexDiff) {
                long long oldBucketId = (long long)nums[i - indexDiff] / size;
                if (nums[i - indexDiff] < 0) oldBucketId--;
                buckets.erase(oldBucketId);
            }
        }

        return false;
    }
};

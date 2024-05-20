class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return findSum(nums, 0, 0);
    }

private:
    int findSum(vector<int>& nums, int curInd, int curNum) {
        if (curInd == nums.size()) {
            return curNum;
        }

        int includeInXor = findSum(nums, curInd + 1, curNum ^ nums[curInd]);
        int notIncludeInXor = findSum(nums, curInd + 1, curNum);

        return includeInXor + notIncludeInXor;
    }
};
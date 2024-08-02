class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int countOne=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1) countOne++;
        }

        vector<int> nums1(nums.begin(), nums.end());
        for(int i=0; i<countOne-1; i++){
            nums1.push_back(nums[i]);
        }
        int countZ=0;
        for(int i=0; i<countOne; i++){
            if(nums[i]==0) countZ++;
        }
        int i=0; int j=countOne-1;

        int ans=countZ;
        while(i<nums1.size() && j<nums1.size()-1){
            if(nums1[i]==0) countZ--;
            if(nums1[j+1] == 0) countZ++;
            i++;
            j++;
            ans=min(ans, countZ);
        }

        return ans;
    }
};
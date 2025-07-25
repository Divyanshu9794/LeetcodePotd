class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> final_sorted;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                final_sorted.push_back(nums1[i++]);
            }
            else{
                final_sorted.push_back(nums2[j++]);
            }
        }
        while(i<m){
            final_sorted.push_back(nums1[i++]);
        }
        while(j<n){
            final_sorted.push_back(nums2[j++]);
        }
        nums1 = final_sorted;
    }
};
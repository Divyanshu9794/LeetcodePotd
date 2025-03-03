class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n);
        int small= 0,large=n-1;
        for(int i=0,j=n-1;i<n;i++,j--){
            if(nums[i]<pivot){
                res[small]=nums[i];
                small++;
            }
            if(nums[j]>pivot){
                res[large]=nums[j];
                large--;
            }
        }
        while(small<=large){
            res[small]=pivot;
            small++;
        }
        return res;


        
    }
};
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> o;
        vector<int> e;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                e.push_back(nums[i]);
            }
            else{
                o.push_back(nums[i]);

            }
        }
        int k=0;
        int l=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans.push_back(e[k]);
                k++;
            }
            else{
                ans.push_back(o[l]);
                l++;
            }
        }
        return ans;

    }
};
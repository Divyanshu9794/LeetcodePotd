class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> o;
        vector<int> e;
        for(int i=0;i<n;i++){
            if(i%2==0){
                e.push_back(nums[i]);
            }
            else{
                o.push_back(nums[i]);

            }
        }
        sort(e.begin(),e.end());
        sort(o.begin(),o.end());
        reverse(o.begin(), o.end());
        nums.clear();
        
        for(int i=0 ; i<o.size() ; i++)
        {
            nums.push_back(o[i]);
        }
        int j=0;
        for(int i=0 ; i<e.size() ; i++)
        {
            nums.insert(nums.begin()+j, e[i]);
            j += 2;
        }
        return nums;
    }
};
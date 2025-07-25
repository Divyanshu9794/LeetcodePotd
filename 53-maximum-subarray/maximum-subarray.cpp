class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN,sum=0,start=-1,ansstart=-1,ansend=-1;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(sum==0){
                start =i;
            }
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
                ansstart=start;
                ansend=i;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};
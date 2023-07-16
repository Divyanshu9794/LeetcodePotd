class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;
        int mxfreq=0;
        int domin=0;
        int domico=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>mxfreq){
                mxfreq=freq[nums[i]];
                domin=nums[i];
                domico=mxfreq;
            }
        }
        if(domico*2<=n){
            return -1;
            
        }
        int leftfreq=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==domin){
                leftfreq++;
            }
            int rightfreq=domico-leftfreq;
            if(leftfreq*2>i+1 && rightfreq*2>n-i-1){
                return i;
            }
        }
        return -1;
        
    }
};

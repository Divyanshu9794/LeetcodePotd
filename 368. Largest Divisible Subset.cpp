class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n= arr.size();
        vector<int> dp(n,1),hash(n);
        int maxi=1;
        int li=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[i]%arr[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                li=i;
            }
        }
        vector<int> temp;
        temp.push_back(arr[li]);
        while(hash[li] != li){
            li = hash[li];
            temp.push_back(arr[li]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
            
    }
};

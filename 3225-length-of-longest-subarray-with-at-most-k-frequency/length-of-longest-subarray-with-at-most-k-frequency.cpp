class Solution {
public:
   int maxSubarrayLength(vector<int>& arr, int k) {
        int i = 0;
        int j = 0;
        int n = arr.size();
        unordered_map<int,int> mp;
        
        int ans = 0;
        while(j < n)
        {
            mp[arr[j]]++;
            if(mp[arr[j]] > k)
            {
                while(i<j and mp[arr[j]] > k)
                {
                    if(mp[arr[i]] == 1)
                        mp.erase(arr[i]);
                    else
                        mp[arr[i]]--;
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            
            j++;
        }
        
        return ans;
    }
};

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto& cnt:arr){
            if(mp[cnt]==1){
                k--;
                if(k==0){
                    return cnt;
                }
            }
        }
        return "";
        
    }
};
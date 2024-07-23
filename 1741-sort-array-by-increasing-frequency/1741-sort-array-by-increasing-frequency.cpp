class Solution {
public:
  static bool cmp(pair<int, int> a, pair<int, int> b){
   if (a.second==b.second){
       return a.first<b.first;
   }
   return a.second>b.second;
}    
   vector<int> frequencySort(vector<int>& nums) {
    
        vector<int> ans;
        map<int,int> mp;
        for (int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> res;
        for (auto i: mp){
            res.push_back({i.first, i.second});
        }
        sort(res.begin(), res.end(), cmp);
            for (auto i: res){
            while (i.second--){
            ans.push_back(i.first);
            }    
        }
        reverse(ans.begin(), ans.end());
            return ans;
    }
 };
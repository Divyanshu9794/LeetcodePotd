class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n= grid.size();
        int repeating =0,missing =0;
        unordered_map<int,int> mp;
        for(auto &i: grid){
            for(int a: i){
                mp[a]++;
            }
        }
        for(int i=1;i<=n*n;i++){
            if(!mp.count(i)){
                missing= i;
            }
            else if(mp[i]==2){
                repeating = i;
            }
        }

        return {repeating,missing};
        
    }
};
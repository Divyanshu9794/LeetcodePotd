class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        int n = edges.size();
        for(int i=0;i<n;i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        int node=0;
        for(auto a:mp){
            node++;
        }
        for(auto a:mp){
            if(a.second==node-1){
                return a.first;
            }
        }
        return 1;
    }
};
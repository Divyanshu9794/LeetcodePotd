class Solution {
public:
    int res= INT_MAX;
    vector<int>val;
    vector<vector<int>>adj;
    int total;
    int dfs2(int x ,int par,int ans1,int ancestor){
        int xorr = val[x];
        for(auto &children:adj[x]){
            if(children==par){
                continue;
            }
            xorr^=dfs2(children,x,ans1,ancestor);
        }
        if(par==ancestor){
            return xorr;
        }
        res = min(res,max({ans1,xorr,total^ans1^xorr})-min({ans1,xorr,total^ans1^xorr}));

        return xorr;
    }
    int dfs(int x,int par){
        int xorr = val[x];
        for(auto &children:adj[x]){
            if(children==par){
                continue;
            }
            xorr^=dfs(children,x);
        }
        for(auto &children:adj[x]){
            if(children==par){
                dfs2(children,x,xorr,x);
            }
        }
        return xorr;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> ad(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0],v=edges[i][1];
            ad[u].push_back(v);
            ad[v].push_back(u);
        }
        int sum =0;
        for(auto x:nums){
            sum^=x;
        }
        val=nums;
        adj=ad;
        total = sum;
        dfs(0,-1);
        return res;

        
    }
};
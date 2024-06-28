class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        vector<int> mat[n];
        for(auto vec:roads)
        {
            int a = vec[0], b = vec[1];
            mat[a].push_back(b);
            mat[b].push_back(a);
        }
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
            pq.push({mat[i].size(), i});

        int cost = n;
        vector<int>mx(n);
        while(!pq.empty())
        {
            mx[pq.top().second] = cost--;
            pq.pop();
        }

        long long ans = 0;
        set<pair<int,int>>seen;
        for(int i=0;i<n;i++)
        {
            for(auto val:mat[i])
            {
                if(not seen.count({i, val}))
                {
                    ans += mx[i] + mx[val];
                    seen.insert({i, val});
                    seen.insert({val, i});
                }
            }
        }
        return ans;
    }
};
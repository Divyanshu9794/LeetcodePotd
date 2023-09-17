class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        int n = adj.size(), endMask = (1 << n) - 1;
        if(n == 1) return 0;
        
        set<pair<int,int>> s;
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++)
        {
            q.push({i, 1<<i});
            s.insert({i, 1<<i});
        }
        int steps = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                pair<int,int> front = q.front();
                q.pop();
                
                for(int i : adj[front.first])
                {
                    int mask = front.second | (1 << i);
                    
                    if(mask == endMask) 
                    {
                        return steps+1;
                    }
                    
                    if(s.find({i, mask}) == s.end())
                    {
                        q.push({i, mask});
                        s.insert({i, mask});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto edge: meetings)
        {
            int u = edge[0], v=edge[1], time = edge[2];
            graph[u].push_back({v,time});
            graph[v].push_back({u,time});
        }
        vector<int>reached(n,INT_MAX);
        reached[0] = 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({firstPerson,0});
        while(!q.empty())
        {
            int u = q.front().first, time = q.front().second;
            q.pop();
            reached[u] = time;
            for(auto edge: graph[u])
            {
                int v = edge.first, meetTime = edge.second;
                if(meetTime >= time && reached[v] > meetTime)
                {
                    //decide whetther the node is already reached or not
                    q.push({v,meetTime});
                }
            }
        }
        vector<int>res;
        for(int i=0; i<n; i++)
        {
            if(reached[i]!= INT_MAX)
                res.push_back(i);
        }

        return res;
    }
};
class Graph {
public:
    typedef long long ll;
    vector<vector<pair<int, int>>> G;
    int n;
    
    Graph(int _n, vector<vector<int>>& edges) {
        this -> n = _n;
        G.resize(n);
        for(auto& e : edges) G[e[0]].push_back({e[1], e[2]});
    }
    
    void addEdge(vector<int> edge) {
        G[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        // Dijktra's algo
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, node1});
        
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
        
        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if(u == node2) return d;
            if(dist[u] < d) continue;
            for(auto [v, wt] : G[u]) {
               if(dist[v] > dist[u] + wt) {
                    pq.push({d + wt, v});
                    dist[v] = d + wt;
               }
            } 
        }
        
        return -1;
    }
};
class Solution {
public:
    int minimumTime(int n,vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> graph;
        vector<int> in_degree(n + 1, 0);
        for (auto& relation : relations) {
            graph[relation[0]].push_back(relation[1]);
            in_degree[relation[1]]++;
        }

        vector<int> dist = time;
        dist.insert(dist.begin(), 0);
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front(); q.pop();
            for (int next_course : graph[course]) {
                dist[next_course] = max(dist[next_course], dist[course] + time[next_course - 1]);
                in_degree[next_course]--;
                if (in_degree[next_course] == 0) {
                    q.push(next_course);
                }
            }
        }

        return *max_element(dist.begin(), dist.end());
    }
};
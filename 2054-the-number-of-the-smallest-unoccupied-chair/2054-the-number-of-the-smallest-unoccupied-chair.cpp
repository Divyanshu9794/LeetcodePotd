class Solution {
public:
    int smallestChair(vector<vector<int>>& t, int k) 
    {
        int a = t[k][0], b = t[k][1];
        priority_queue<int, vector<int>, greater<int>> q1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q2;

        sort(t.begin(), t.end());
        q1.push(0);
        for (int i = 0; i < t.size(); i++)
        {
            while (!q2.empty() && q2.top().first <= t[i][0])
            {
                q1.push(q2.top().second);
                q2.pop();
            }
            int ci = q1.top();
            q1.pop();
            if (q1.size() == 0) q1.push(ci+1);
            if (t[i][0] == a) return ci;
            q2.push({t[i][1], ci});
        }
        return 0;
    }
};
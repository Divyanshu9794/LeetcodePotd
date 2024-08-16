class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        priority_queue<pair<int,int>>pq;
        int N=arr.size();
        int res=INT_MIN;

        for(int i=0;i<N;i++)
        {
           int n=arr[i].size();
           pq.push({arr[i][n-1],i});
        }

        for(int i=0;i<N;i++)
        {
            auto top=pq.top();
            if(top.second==i)
            {
                pq.pop();
                auto x=pq.top();
                pq.push(top);
                top=x;
            }
           
            res=max(res, abs(arr[i][0]-top.first));

        }
        return res;
    }
};
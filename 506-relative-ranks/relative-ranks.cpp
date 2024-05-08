class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i < score.size();i++)
            pq.push({score[i],i});

        vector<string> ans(score.size());
        int i = 1;
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            if(i == 1)
                ans[temp.second] = "Gold Medal";
            else if(i == 2)
                ans[temp.second] = "Silver Medal";
            else if(i == 3)
                ans[temp.second] = "Bronze Medal";
            else
                ans[temp.second] = to_string(i);
            i++;
        }
        return ans;
    }
};
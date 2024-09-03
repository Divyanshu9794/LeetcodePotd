class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> results;
        priority_queue<int> maxHeap;
        
        for (auto& query : queries) {
            int x = query[0];
            int y = query[1];
            int distance = abs(x) + abs(y);
            
            maxHeap.push(distance);
            
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
            
            if (maxHeap.size() == k) {
                results.push_back(maxHeap.top());
            } else {
                results.push_back(-1);
            }
        }
        
        return results;
    }
};

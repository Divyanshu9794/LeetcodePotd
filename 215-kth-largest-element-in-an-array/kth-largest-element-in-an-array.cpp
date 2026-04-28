class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        for(int i=1;i<k;i++){
            
                pq.pop();
        }
        return pq.top();
    }
};
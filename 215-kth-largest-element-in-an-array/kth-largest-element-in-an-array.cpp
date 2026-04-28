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

// class Solution {
//   public:
//     int kthSmallest(vector<int> &arr, int k) {
//         // code here
//         priority_queue<int> pq;
//         for(int i=0;i<k;i++){
//             pq.push(arr[i]);
//         }
//         int n = arr.size();
//         for(int i=k;i<n;i++){
//             if(arr[i]<pq.top()){
//                 pq.pop();
//                 pq.push(arr[i]);
//             }
//         }
//         return pq.top();
//     }
// };
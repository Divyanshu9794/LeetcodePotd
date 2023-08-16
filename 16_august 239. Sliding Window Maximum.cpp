class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<k;i++){
            while(!dq.empty() && arr[i]>=arr[dq.back()]){
                dq.pop_back();
            
            }
            dq.push_back(i);
        }
        for(int i=k;i<n;i++){
            ans.push_back(arr[dq.front()]);
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && arr[i]>=arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);
        return ans ;
        
    }
};

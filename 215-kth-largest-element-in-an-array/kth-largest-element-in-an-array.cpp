class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        
        // int l = nums.size();
        // sort(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.end());
        // if((k-1)<0){
        //     return nums[0];
        // }
        // return nums[k-1];

        priority_queue<int, vector<int>, greater<int>> q;

        for (int i = 0; i < arr.size(); i++) {
            q.push(arr[i]);
            if (q.size() > k) {
                q.pop();  
            }
        }
        return q.top(); 
    
    }
};
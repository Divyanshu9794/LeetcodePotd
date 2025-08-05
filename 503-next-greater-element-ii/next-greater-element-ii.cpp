class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans ;
        int n = nums.size();
        stack<int> st;
        for(int i= 2*n-1 ;i>=0;i--){
            while(!st.empty() && st.top()<= nums[i%n]){
                st.pop();

            }
            if(i<n){
                ans.push_back(st.empty()?-1:st.top());

            }
            st.push(nums[i%n]);

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxarea =0;int nse=0, pse=0;
        int el =0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                el = st.top();
                st.pop();
                nse = i;
                pse = st.empty()?-1:st.top();
                maxarea = max(maxarea, heights[el]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = n;
            el = st.top();
            st.pop();
            pse = st.empty()?-1:st.top();
            maxarea = max(maxarea , (nse-pse-1)* heights[el]);
        }   
        return maxarea;
    }
};
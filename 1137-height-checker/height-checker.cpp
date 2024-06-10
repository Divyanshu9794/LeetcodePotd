class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();

        int count =0;
        vector<int> expected;
        expected=heights;
        sort(heights.begin(),heights.end());
        for(int i=0;i<n;i++){
            if(heights[i]!=expected[i]){
                count++;
            }
        }
        return count;
    }
};
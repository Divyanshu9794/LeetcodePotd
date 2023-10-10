class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
             int start1, end1, start2, end2;
         sort(intervals.begin(), intervals.end());
         int n = intervals.size();
         vector<vector<int>> ans;
         int ans_size ;
         ans.push_back({intervals[0][0], intervals[0][1]});
         for(int i=1;i<n;i++){
              ans_size = ans.size();
              start1 = ans[ans_size-1][0];
              end1 = ans[ans_size-1][1];
              start2 = intervals[i][0];
              end2 = intervals[i][1];
             if(end1 >= start2){
                ans.pop_back();
                end1 = max(end1,end2);
                ans.push_back({start1,end1});
             }else{
                 ans.push_back({start2, end2});
             }
         }
        return ans; 
    }
};
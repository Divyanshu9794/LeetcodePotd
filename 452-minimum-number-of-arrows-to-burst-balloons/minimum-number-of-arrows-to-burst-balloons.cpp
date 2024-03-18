bool cmp(vector<int>&a, vector<int>&b){
    if(a[1] == b[1])return a[0] <= b[0];
    return a[1] <= b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ans = 0;
        int n = points.size();
        int ind = 0;
        while(ind < n){
            int left = points[ind][1];
            ans++;
            ind++;
            while(ind < n and points[ind][0] <= left)ind++;
        }
        return ans;
    }
};
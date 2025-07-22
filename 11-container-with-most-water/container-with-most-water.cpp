class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int maxarea =0;
        while(l<r){
            int width = r-l;
            int h = min(height[l],height[r]);
            int currarea = width * h;
            maxarea = max(maxarea,currarea);
            height[l]<height[r]? l++:r--;
        }
        return maxarea;
        
    }
};
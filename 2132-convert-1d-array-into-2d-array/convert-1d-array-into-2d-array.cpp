class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size=original.size();
        if(m*n!=size)
        {
            return {};
        }
        vector<vector<int>>ans(m,vector<int>(n));
        int col=0,row=0;
        for(int i=0;i<size;i++)
        {
            if(col<n)
            {
                ans[row][col]=original[i];
                col+=1;
            }
            if(col==n)
            {
                row+=1;
                col=0;
            }

        }
        return ans;
    }
};
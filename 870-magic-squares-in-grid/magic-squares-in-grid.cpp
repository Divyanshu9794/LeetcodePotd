class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid){
        unordered_set<int> st;
        for(int x=i;x<i+3;x++){
            for(int y=j;y<j+3;y++){
                int cur = grid[x][y];
                if( cur > 9 || cur < 1){
                    return false;
                }else{
                    if(st.find(cur) == st.end()){
                        st.insert(cur);
                    }else{
                        return false;
                    }
                }
            }
        }
        int s = grid[i][j]+grid[i][j+1]+grid[i][j+2];
        for(int x=i;x<i+3;x++){
            int temp_s =0;
            for(int y=j;y<j+3;y++){
                temp_s += grid[x][y];
            }
            if(temp_s != s) return false;
        }
        for(int x=j;x<j+3;x++){
            int temp_s =0;
            for(int y=i;y<i+3;y++){
                temp_s += grid[y][x];
            }
            if(temp_s != s) return false;
        }
        int dia_1 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        if(dia_1 != s) return false;
        int dia_2 = grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2];
        if(dia_2 != s) return false;

        return true;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size() < 3 || grid[0].size() < 3) return 0;
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        // cout << "here " << endl;
        for(int i=0;i<n-2;i++){
            // cout << "i : " << i << endl;
            for(int j=0;j<m-2;j++){
                // cout << "j : " << j << endl;
                if(check(i,j,grid)) res++;
            }
        }
        return res;
    }
};

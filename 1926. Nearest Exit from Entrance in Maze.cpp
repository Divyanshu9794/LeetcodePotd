class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        set<pair<int,int>>st;
        int n=maze.size();
        int m=maze[0].size();
        
        // first row and last exit
        for(int i=0;i<m;i++){
            if(maze[0][i]=='.')st.insert({0,i});
            if(maze[n-1][i]=='.')st.insert({n-1,i});
        }

        for(int i=0;i<n;i++){
            if(maze[i][0]=='.')st.insert({i,0});
            if(maze[i][m-1]=='.')st.insert({i,m-1});
        }
        int row=entrance[0];
        int col=entrance[1];

        if(st.find({row,col})!=st.end())
            st.erase({row,col});

        if(st.size()==0)return -1;

        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>vist(n,vector<int>(m,0));

        pq.push({0,{row,col}});
        vist[row][col]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            int steps=pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(st.find({row,col})!=st.end()){
                return steps;
            }

            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m and 
                  maze[nr][nc]=='.' and !vist[nr][nc]){
                      vist[nr][nc]=1;
                      pq.push({steps+1,{nr,nc}});
                  }
            }
        }

        return -1;


    }
};

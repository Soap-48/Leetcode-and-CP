class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int dx[4]={-1,+1,0,0};
        int dy[4]={0,0,-1,+1};
        auto bfs=[&](pair<int,int> s){
            queue<pair<int,int>> q;
            q.push(s);
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i+=1){
                    int xx=x+dx[i],yy=y+dy[i];
                    if(xx>=0&&xx<n&&yy>=0&&yy<m&&grid[xx][yy]=='1'){
                        grid[xx][yy]='0';
                        q.push({xx,yy});
                    }
                }
            }
        };
        // for(int i=0;i<m;i+=1){
        //     if(grid[0][i]==1){
        //         grid[0][i]=0;
        //         bfs({0,i});
        //     }
        //     if(grid[n-1][i]==1){
        //         grid[n-1][i]=0;
        //         bfs({n-1,i});
        //     }
        // }
        // for(int i=0;i<n;i+=1){
        //     if(grid[i][0]==1){
        //         grid[i][0]=0;
        //         bfs({i,0});
        //     }
        //     if(grid[i][m-1]==1){
        //         grid[i][m-1]=0;
        //         bfs({i,m-1});
        //     }
        // }
        int comp=0;
        for(int i=0;i<n;i+=1)
            for(int j=0;j<m;j+=1)
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    comp+=1;
                    bfs({i,j});
                }
        return comp;
    }
};
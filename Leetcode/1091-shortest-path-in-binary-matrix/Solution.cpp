class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> d(n,vector<int>(n,1e9));
        queue<pair<int,int>> q;
        if(grid[0][0]==0)
            d[0][0]=1,q.push({0,0});
        int dx[]={-1,-1,-1,0,0,+1,+1,+1};
        int dy[]={-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            auto &[x,y]=q.front();
            for(int i=0;i<8;i+=1){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx>=0&&xx<n&&yy>=0&&yy<n&&grid[xx][yy]==0&&d[xx][yy]==1e9){
                    d[xx][yy]=d[x][y]+1;
                    q.push({xx,yy});
                }
            }
            q.pop();
        }
        if(d[n-1][n-1]==1e9)
            return -1;
        else
            return d[n-1][n-1];
    }
};
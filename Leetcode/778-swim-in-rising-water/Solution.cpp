class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> d(n,vector<int>(n,1e8));
        d[0][0]=grid[0][0];
        int dx[]={0,0,-1,+1};
        int dy[]={+1,-1,0,0};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({grid[0][0],{0,0}});
        while(!q.empty()){
            auto [i,j]=q.top();
            q.pop();
            if(i>d[j.first][j.second]) continue;
            for(int k=0;k<4;k+=1){
                int x=j.first+dx[k],y=j.second+dy[k];
                if(x>=0&&x<n&&y>=0&&y<n){
                    if(d[x][y]>max(i,grid[x][y])){
                        d[x][y]=max(i,grid[x][y]);
                        q.push({d[x][y],{x,y}});
                    }
                }
            }
        }
        return d[n-1][n-1];
    }
};
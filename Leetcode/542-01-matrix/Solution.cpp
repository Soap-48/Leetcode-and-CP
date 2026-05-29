class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),-1));
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i+=1)
            for(int j=0;j<mat[0].size();j+=1)
                if(mat[i][j]==0){
                    vis[i][j]=0;
                    q.push({i,j});
                }
        int dx[4]={-1,+1,0,0};
        int dy[4]={0,0,-1,+1};
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;k+=1){
                int x=i+dx[k],y=j+dy[k];
                if(x>=0&&x<mat.size()&&y>=0&&y<mat[0].size()&&vis[x][y]==-1){
                    vis[x][y]=vis[i][j]+1;
                    q.push({x,y});
                }
            }
        }
        return vis;
    }
};
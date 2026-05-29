class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        int dx[4]={-1,+1,0,0};
        int dy[4]={0,0,-1,+1};
        vector<vector<bool>> vis(n,vector<bool>(m,false))      ;
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        auto bfs=[&](pair<int,int> s){
            queue<pair<int,int>> q;
            q.push(s);
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                ans[x][y]='O';
                for(int i=0;i<4;i+=1){
                    int xx=x+dx[i],yy=y+dy[i];
                    if(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy]==false&&board[xx][yy]=='O'){
                        vis[xx][yy]=true;
                        q.push({xx,yy});
                    }
                }
            }
        };
        for(int i=0;i<m;i+=1){
            if(vis[0][i]==false&&board[0][i]=='O'){
                vis[0][i]=true;
                bfs({0,i});
            }
            if(vis[n-1][i]==false&&board[n-1][i]=='O'){
                vis[n-1][i]=true;
                bfs({n-1,i});
            }
        }
        for(int i=0;i<n;i+=1){
            if(vis[i][0]==false&&board[i][0]=='O'){
                vis[i][0]=true;
                bfs({i,0});
            }
            if(vis[i][m-1]==false&&board[i][m-1]=='O'){
                vis[i][m-1]=true;
                bfs({i,m-1});
            }
        }
        board=ans;
    }

};
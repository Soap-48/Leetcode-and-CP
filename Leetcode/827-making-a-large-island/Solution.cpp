class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> parent(n*n,-1);
        vector<int> size(n*n,1);
        auto find=[&](auto &self,int a)->int{
            if(parent[a]==a)
                return a;
            else
                return parent[a]=self(self,parent[a]);
        };
        auto chunion=[&](int a,int b)->void{
            a=find(find,a);
            b=find(find,b);
            if(a!=b){
                if(size[a]<size[b])
                    swap(a,b);
                parent[b]=a;
                size[a]+=size[b];
            }
        };
        int dx[]={0,-1,1,0};
        int dy[]={-1,0,0,1};
        for(int i=0;i<n;i+=1)
            for(int j=0;j<n;j+=1){
                if(grid[i][j]==1){
                    parent[n*i+j]=n*i+j;
                    for(int k=0;k<2;k+=1){
                        int x=i+dx[k],y=j+dy[k];
                        if(x>=0&&y>=0&&grid[x][y]==1)
                            chunion(n*i+j,n*x+y);
                    }
                }
            }
        int ans=0;
        for(int i=0;i<n;i+=1)
            for(int j=0;j<n;j+=1){
                if(grid[i][j]==0){
                    int siz=1;
                    set<int> s;
                    for(int k=0;k<4;k+=1){
                        int x=i+dx[k],y=j+dy[k];
                        if(x>=0&&x<n&&y>=0&&y<n&&grid[x][y]==1)
                            s.insert(find(find,n*x+y));
                    }
                    for(auto &l:s)
                        siz+=size[l];
                    ans=max(ans,siz);
                }
                else
                    ans=max(ans,size[n*i+j]);
            }
        return ans;
    }
};
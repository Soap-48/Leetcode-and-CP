class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e=connections.size();
        if(e<n-1)
            return -1;
        vector<vector<int>> adj(n);
        for(vector<int> &i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        auto dfs=[&vis,&adj](auto &self,int i)->void{
            vis[i]=1;
            for(int &j:adj[i])
                if(vis[j]==0)
                    self(self,j);
        };
        int c=0;
        for(int i=0;i<n;i+=1)
            if(vis[i]==0){
                c+=1;
                dfs(dfs,i);
            }
        return c-1;
    }

};
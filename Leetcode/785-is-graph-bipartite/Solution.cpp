class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        queue<int> q;
        for(int i=0;i<n;i+=2){
            if(vis[i]==0){
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int &i=q.front();
                    for(int &j:graph[i]){
                        if(vis[j]==0){
                            vis[j]=(3^vis[i]);
                            q.push(j);
                        }
                        else if(vis[j]==vis[i])
                            return false;
                    }
                    q.pop();
                }
            }
        }
        return true;
    }
};
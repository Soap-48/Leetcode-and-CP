class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<array<int,2>>> adj(n);
        for(vector<int> &i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        q.push({0,0});
        vector<long long> d(n,1e17),c(n,0);//,p(n,-1);
        c[0]=1;
        d[0]=0;
        while(!q.empty()){
            auto [i,j]=q.top();
            q.pop();
            if(i>d[j])  continue;
            for(auto &[x,y]:adj[j]){
                if(d[x]==i+y)
                    c[x]=(c[x]+c[j])%1000000007;
                else if(d[x]>i+y){
                    d[x]=i+y;
                    c[x]=c[j];
                   // p[x]=j;
                    q.push({d[x],x});
                }
            }
        }
        return c[n-1];
    }
};
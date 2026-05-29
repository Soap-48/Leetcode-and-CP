class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<array<int,2>>> adj(n+1);
        for(vector<int> &i:times)
            adj[i[0]].push_back({i[1],i[2]});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});
        vector<int> d(n+1,1e9);
        d[k]=0;
        while(!q.empty()){
            auto [i,j]=q.top();
            q.pop();
            if(i>d[j])  continue;
            for(auto &[x,y]:adj[j]){
                if(d[x]>i+y){
                    d[x]=i+y;
                    q.push({d[x],x});
                }
            }
        }
        int ans=*max_element(next(d.begin()),d.end());
        return (ans==1e9)?-1:ans;
    }
};
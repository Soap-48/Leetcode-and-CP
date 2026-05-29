#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

int n;

void dfs(vector<vi> &a,vector<int> &path){
    vector<int> dist(n+1,-1),parent(n+1,-1);
    dist[1]=0;
    queue<int> q;
    q.push(1);
    int far=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:a[u]){
            if(dist[v]==-1)  {
                dist[v]=dist[u]+1;
                parent[v]=u;
                q.push(v);
            }
            if(dist[v]>dist[far]){
                far=v;
            }
        }
    }
    path.push_back(far);
    int i=far;
    while(i!=1){
        i=parent[i];
        path.push_back(i);
    }
    reverse(all(path));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> a(n-1);
        vector<vi> adj(n+1);
        for(int i=0;i<n-1;++i){
            cin>>a[i].first;cin>>a[i].second;
            adj[a[i].first].push_back(a[i].second);
            adj[a[i].second].push_back(a[i].first);
        }
        vi path;
        dfs(adj,path);
        vector<pair<int,int>> place;
        for(int i=1;i<path.size();++i){
            place.push_back(pair(path[i-1],path[i]));
        }
        int ans=0,it=0;
        while(it<place.size()){
            for(auto k:a){
                if(k==place[it]||((k.first)==place[it].second&&k.second==place[it].first)){
                    it++;
                }
            }
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
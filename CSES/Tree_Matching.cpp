#include <bits/stdc++.h>
using namespace std;

long long dfs(vector<vector<int>> &adj,vector<int> &vis,vector<long long> &in,vector<long long> &out,int i){
    long long sumin=0,maxo=0;
    for(int j:adj[i]){
        if(vis[j]==0){
            vis[j]=1;
            dfs(adj,vis,in,out,j);
            sumin+=in[j];
            maxo=max(maxo,1+out[j]-in[j]);
        }
    }
    in[i]=sumin+maxo;
    out[i]=sumin;
    return max(in[i],out[i]);
}

int main() {
	// your code goes here
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    int u,v;
    for(int i=1;i<n;i+=1){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    vector<long long> in(n+1,0),out(n+1,0);
    vis[1]=1;
    cout<<dfs(adj,vis,in,out,1);
    return 0;
}

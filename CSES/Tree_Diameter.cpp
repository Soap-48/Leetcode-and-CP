#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj,vector<int> &p,vector<int> &d,int i){
    for(int j:adj[i]){
        if(j!=p[i]){
            p[j]=i;
            d[j]=d[i]+1;
            bfs(adj,p,d,j);
        }
    }
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
    vector<int> p(n+1,-1);
    vector<int> d(n+1,0);
    bfs(adj,p,d,1);
    int ma=-1,in=-1;
    for(int i=1;i<=n;i+=1){
        if(d[i]>ma){
            ma=d[i];
            in=i;
        }
    }
    for(int i=1;i<=n;i+=1){
        d[i]=0;
        p[i]=-1;
    }
    bfs(adj,p,d,in);
    cout<<(*max_element(d.begin(), d.end()));
    return 0;
}

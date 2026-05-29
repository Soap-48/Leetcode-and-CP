#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> adj(n+1);
  vector<int> indeg(n+1,0);
  for(int i=0;i<m;i+=1){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    indeg[v]+=1;
  }
  queue<int> q;
  for(int i=1;i<=n;i+=1)
    if(indeg[i]==0)
      q.push(i);
  vector<int> ans;
  while(!q.empty()){
    int i=q.front();
    q.pop();
    ans.push_back(i);
    for(int j:adj[i]){
      indeg[j]-=1;
      if(indeg[j]==0)
        q.push(j);
    }
  }
  vector<int> d(n+1,0);
  for(int i=0;i<n;i+=1){
    for(int j:adj[ans[i]]){
      d[j]=max(d[j],d[ans[i]]+1);
    }
  }
  cout<<*max_element(d.begin(),d.end());
  return 0;
}

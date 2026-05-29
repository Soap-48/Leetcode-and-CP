#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> adj(n+1);
  int u,v;
  vector<int> in(n+1,0);
  for(int i=0;i<m;i+=1){
    cin>>u>>v;
    adj[u].push_back(v);
    in[v]+=1;
  }
  queue<int> q;
  for(int i=1;i<=n;i+=1){
    if(in[i]==0)
      q.push(i);
    }
  vector<int> ans;
  while(!q.empty()){
    int i=q.front();
    q.pop();
    ans.push_back(i);
    for(int j:adj[i]){
      in[j]-=1;
      if(in[j]==0)
        q.push(j);
    }
  }
  if(ans.size()<n)
    cout<<"IMPOSSIBLE";
  else
    for(int i:ans)
      cout<<i<<' ';
  return 0;
}
// #include<bits/stdc++.h>
// #define ll long long
// const ll inf=1e17;

// using namespace std;

// int main(){
//   int n,m;
//   cin>>n>>m;
//   vector<vector<array<ll,2>>> adj(n+1),aadj(n+1);
//   int a,b,c;
//   for(int i=0;i<m;i+=1){
//   cin>>a>>b>>c;
//   adj[a].push_back({b,c});
//   aadj[b].push_back({a,c});
//   }
//   vector<ll> d1(n+1,inf),d2(n+1,inf),p1(n+1,0),p2(n+1,0);
//   d1[1]=0;d2[n]=0;p1[1]=1;p2[n]=1;
//   priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
//   q.push({0,1});
//   while(!q.empty()){
//     auto i=q.top();
//     q.pop();
//     ll w=i.first,x=i.second;
//     if(w>d1[x])  continue;
//     for(auto &[j,k]:adj[x]){
//       if(d1[j]>w+k){
//         d1[j]=w+k;
//         p1[j]=p1[x]+1;
//         q.push({d1[j],j});
//       }
//     }
//   }
//   q.push({0,n});
//   while(!q.empty()){
//     auto i=q.top();
//     q.pop();
//     ll w=i.first,x=i.second;
//     if(w>d2[x])  continue;
//     for(auto &[j,k]:aadj[x]){
//       if(d2[j]>w+k){
//         d2[j]=w+k;
//         p2[j]=p2[x]+1;
//         q.push({d2[j],j});
//       }
//     }
//   }  
//   ll mini=d1[n];
//   ll num=0,minl=inf,maxl=0;
//   for(int i=1;i<n;i+=1){
//     for(auto &[j,k]:adj[i]){
//       if(d1[i]+d2[j]+k==mini){
//         num+=1;
//         minl=min(minl,p1[i]+p2[j]);
//         maxl=max(maxl,p1[i]+p2[j]);
//       }
//     }
//   }
//   cout<<mini<<' '<<num<<' '<<minl<<' '<<maxl;
//   return 0;
// }


// #include<bits/stdc++.h>
// #define ll long long
// const ll inf=1e17;
// const ll MOD=1000000007;

// using namespace std;

// int main(){
//   int n,m;
//   cin>>n>>m;
//   vector<vector<array<ll,2>>> adj(n+1);
//   vector<int> indeg(n+1,0);
//   int a,b,c;
//   for(int i=0;i<m;i+=1){
//     cin>>a>>b>>c;
//     adj[a].push_back({b,c});
//     indeg[b]+=1;
//   }
//   queue<int> q;
//   for(int i=1;i<=n;i+=1){
//     if(indeg[i]==0)
//       q.push(i);
//   }
//   vector<int> ans;
//   while(!q.empty()){
//     int i=q.front();
//     q.pop();
//     ans.push_back(i);
//     for(auto &[j,k] : adj[i]){
//       indeg[j]-=1;
//       if(indeg[j]==0)
//         q.push(j);
//     }
//   }
// //   if(ans.size()<n){
// //     cout<<"-1";return 0;
// //   }
//   vector<ll> d(n+1,inf);
//   d[1]=0;
//   vector<ll> p(n+1,0),mini(n+1,inf),maxi(n+1,0);
//   mini[1]=0;maxi[1]=0;
//   p[1]=1;
//   int s=find(ans.begin(),ans.end(),1)-ans.begin();
//   for(int i=s;i<ans.size();i+=1){
//     if(d[ans[i]]!=inf){
//       for(auto &[j,k]:adj[ans[i]]){
//         if(d[j]>d[ans[i]]+k){
//           d[j]=(d[ans[i]]+k);
//           p[j]=p[ans[i]];
//           mini[j]=1+mini[ans[i]];
//           maxi[j]=1+maxi[ans[i]];
//         }
//         else if(d[j]==d[ans[i]]+k){
//           p[j]=(p[j]+p[ans[i]])%MOD;
//           mini[j]=min(mini[j],1+mini[ans[i]]);
//           maxi[j]=max(maxi[j],1+maxi[ans[i]]);
//         }
//       }
//     }
//   }
//   cout<<d[n]<<' '<<p[n]<<' '<<mini[n]<<' '<<maxi[n];
//   return 0;
// }


#include<bits/stdc++.h>
#define ll long long
const ll MOD=1e9+7;
const ll inf=1e17;

using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<array<ll,2>>> adj(n+1);
  int a,b,c;
  for(int i=0;i<m;i+=1){
    cin>>a>>b>>c;
    adj[a].push_back({b,c});
  }
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  q.push({0,1});
  vector<ll> d(n+1,inf);
  d[1]=0;
  vector<ll> p(n+1,0),mini(n+1,0),maxi(n+1,0);
  mini[1]=0;maxi[1]=0;
  p[1]=1;
  while(!q.empty()){
    auto [w,i]=q.top();
    q.pop();
    if(w>d[i])  continue;
    for(auto &[j,k]:adj[i]){
        if(d[j]>d[i]+k){
          d[j]=d[i]+k;
          p[j]=p[i];
          mini[j]=1+mini[i];
          maxi[j]=1+maxi[i];
          q.push({d[j],j});
        }
        else if(d[j]==d[i]+k){
          p[j]=(p[j]+p[i])%MOD;
          mini[j]=min(mini[j],1+mini[i]);
          maxi[j]=max(maxi[j],1+maxi[i]);
        }
      }
  }
  cout<<d[n]<<' '<<p[n]<<' '<<mini[n]<<' '<<maxi[n];
  return 0;
}
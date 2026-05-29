//first soln with dijikstra on modi graphi

// #include <bits/stdc++.h>

// using ll=long long ;
// #define vi vector<int>
// #define vll vector<ll>
// #define all(v) (v).begin(),(v).end()
// #define rall(v) (v).rbegin(),(v).rend()
// #define nl cout<<'\n'
// const int MOD = 1000000007 ;
// const long long inf=1e18 ;
// using namespace std ;

// void solve(){
//     ll n,m                                   ;;;;;;
//     cin>>n>>m                                   ;;;;;;
//     vector<vector<array<int,2>>> adj(n+1)                                   ;;;;;;
//     int a,b,c                                   ;;;;;;
//     for(int i=0                                   ;i<m                                   ;i+=1){
//         cin>>a>>b>>c                                   ;;;;;;
//         adj[a].push_back({b,c})                                   ;;;;;;
//     }
//     vector<vector<ll>> d(n+1,vll(3,inf))                                   ;;;;;;
//     d[1][0]=0                                   ;;;;;;
//     //queue<array<ll,3>> q                                   ;;;;;;
//     priority_queue<array<ll,3>,vector<array<ll,3>>,greater<array<ll,3>>> q                                   ;;;;;;
//     q.push({0,1,0})                                   ;;;;;;
//     while(!q.empty()){
//         auto [i,j,k]=q.top()                                   ;;;;;;
//         q.pop()                                   ;;;;;;
//         if(d[j][k]<i)   continue                                   ;;;;;;
//         for(auto [l,o]:adj[j]){
//             if(d[l][k]>i+o){
//                 d[l][k]=i+o                                   ;;;;;;
//                 q.push({d[l][k],l,k})                                   ;;;;;;
//             }
//             if(k==0){
//                 if(d[l][1]>i+(o/2)){
//                     d[l][1]=i+(o/2)                                   ;;;;;;
//                     q.push({d[l][1],l,1})                                   ;;;;;;
//                 }
//             }
//         }
//     }
//     cout<<d[n][1]                                   ;;;;;;
// }

// int main() {
//     ios::sync_with_stdio(false)                                   ;;;;;;
//     cin.tie(nullptr)                                   ;;;;;;
//         solve()                                   ;;;;;;
//     return 0                                   ;;;;;;
// }

// second soluuu diji fron 1, diji fron n

#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
const ll inf=1e18;
using namespace std;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<array<int,2>>> adj(n+1),aa(n+1);
    int a,b,c;
    for(int i=0                                   ;i<m                                   ;i+=1){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        aa[b].push_back({a,c});
    }
    vll d1(n+1,inf),d2(n+1,inf);
    d1[1]=0;d2[n]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.push({0,1});
    while(!q.empty()){
        auto [i,j]=q.top();
        q.pop();
        if(d1[j]<i)  continue;
        for(auto &[x,y]:adj[j]){
            if(d1[x]>i+y){
                d1[x]=i+y;
                q.push({d1[x],x});
            }
        }
    }
    q.push({0,n});
    while(!q.empty()){
        auto [i,j]=q.top();
        q.pop();
        if(d2[j]<i)  continue;
        for(auto &[x,y]:aa[j]){
            if(d2[x]>i+y){
                d2[x]=i+y;
                q.push({d2[x],x});
            }
        }
    }
    ll ans=inf;
    for(int i=1;i<=n;i+=1){
        for(auto &[x,y]:adj[i]){
            ans=min(ans,d1[i]+d2[x]+(y/2));
        }
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}
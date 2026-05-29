// #include <bits/stdc++.h>

// using ll=long long;
// #define vi vector<int>
// #define pb push_back
// #define all(v) (v).begin(),(v).end()
// #define rall(v) (v).rbegin(),(v).rend()
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int N,W;
//     cin>>N>>W;
//     vector<pair<int,int>> a(N);
//     for(int i=0;i<N;i+=1){
//         cin>>a[i].first>>a[i].second;
//     }
//     ll ans=0;
//     vector<vector<ll>> dp(N+1,vector<ll>(W+1,0ll));
//     for(int i=0;i<N;i+=1){
//                 for(int j=0;j<=W;j+=1){
//                 dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
//                 if(j+a[i].first<=W)
//                     dp[i+1][j+a[i].first]=max(dp[i+1][j+a[i].first],dp[i][j]+a[i].second);       
//         }
//     }
//     for(int i=0;i<=W;i+=1)
//         ans=max(ans,dp[N][i]);
//     cout<<ans;
//     return 0;
// }

#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,W;
    cin>>N>>W;
    vector<pair<int,int>> a(N);
    for(int i=0;i<N;i+=1){
        cin>>a[i].first>>a[i].second;
    }
    ll ans=0;
    vector<ll> dp(W+1,0ll);
    for(int i=0;i<N;i+=1){
        for(int j=W;j>=a[i].first;j-=1)
            dp[j]=max(dp[j],dp[j-a[i].first]+a[i].second);
    }
    for(int i=0;i<=W;i+=1)
        ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}
#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<long long>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int MOD = 1000000007;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<vi> dp(n+1,vi(x+1,0));
    vi h(n),s(n);
    for(int i=0;i<n;i+=1)   cin>>h[i];
    for(int i=0;i<n;i+=1)   cin>>s[i];
    for(int i=0;i<n;i+=1){
        for(int j=0;j<=x;j+=1){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(j+h[i]<=x)   dp[i+1][j+h[i]]=max(dp[i+1][j+h[i]],dp[i][j]+s[i]);
        }
    }
    int ans=0;
    for(int i=0;i<=x;i+=1)
        ans=max(ans,dp[n][i]);
    cout<<ans;
    return 0;
}
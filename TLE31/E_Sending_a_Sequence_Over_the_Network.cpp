#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

void solve(){
    int n;
    cin>>n;
    vi a(n+1);
    for(int i=1;i<=n;i+=1)
        cin>>a[i];
    vi dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i+=1){
        if(i-a[i]-1>=0) dp[i]=max(dp[i],dp[i-a[i]-1]);
        if(i+a[i]<=n)   dp[i+a[i]]=max(dp[i+a[i]],dp[i-1]);
    }
    if(dp[n])   cout<<"YES\n";
    else    cout<<"NO\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
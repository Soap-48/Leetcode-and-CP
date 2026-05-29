#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vi c(n);
    for(int i=0;i<n;i+=1)
        cin>>c[i];
    vll dp(x+1,INT_MAX);
    dp[0]=0;
    ll ans=-1;
    for(int i=1;i<=x;i+=1){
        for(int j:c)
          if(i>=j)  dp[i]=min(dp[i],dp[i-j]+1);
    }
    if(dp[x]==INT_MAX)  cout<<-1;
    else cout<<dp[x];
    return 0;
}
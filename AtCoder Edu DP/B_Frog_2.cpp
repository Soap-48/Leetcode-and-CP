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
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    vi dp(n);
    dp[0]=0;
    for(int i=1;i<n;i+=1){
        dp[i]=dp[i-1]+abs(a[i]-a[i-1]);
        for(int j=1;j<=k && i-j>=0;j+=1)
            dp[i]=min(dp[i],dp[i-j]+abs(a[i-j]-a[i]));
    }
    cout<<dp[n-1];
    return 0;
}
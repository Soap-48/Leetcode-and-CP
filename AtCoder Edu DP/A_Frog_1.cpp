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
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    vi dp(n);
    dp[0]=0;
    if(n>1)
        dp[1]=abs(a[1]-a[0]);
    for(int i=2;i<n;i+=1){
        dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i-2]-a[i]));
    }
    cout<<dp[n-1];
    return 0;
}
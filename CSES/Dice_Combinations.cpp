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
    int dp[n+1];
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=n;i+=1){
        dp[i]=0;
        for(int j=1;j<=min(6,i);j+=1)
            dp[i]=(dp[i]+dp[i-j])%1000000007;
    }
    cout<<dp[n];
    return 0;
}
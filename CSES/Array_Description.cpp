#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int MOD = 1000000007;
using namespace std;

int dp[2][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int val,in=0;
    cin>>val;
    if(val==0){
    for(int j=1;j<=m;j+=1)
        dp[0][j]=1;
    }
    else
        dp[0][val]=1;
    for(int i=1;i<n;i+=1){
        in=1-in;
        cin>>val;
        if(val==0){
            for(int j=1;j<=m;j+=1){
                if(j>1)   dp[in][j]=(dp[in][j]+dp[1-in][j-1])%MOD;
                dp[in][j]=(dp[in][j]+dp[1-in][j])%MOD;
                if(j<m)   dp[in][j]=(dp[in][j]+dp[1-in][j+1])%MOD;
            }
        }
        else{
            if(val>1)   dp[in][val]=(dp[in][val]+dp[1-in][val-1])%MOD;
            dp[in][val]=(dp[in][val]+dp[1-in][val])%MOD;
            if(val<m)   dp[in][val]=(dp[in][val]+dp[1-in][val+1])%MOD;
        }
        for(int j=1;j<=m;j+=1)
            dp[1-in][j]=0;
    }
    if(val!=0)
        cout<<dp[in][val];
    else{
        ll ans=0;
        for(int j=1;j<=m;j+=1)
            ans=(ans+dp[in][j])%MOD;
        cout<<ans;
    }
    return 0;
}
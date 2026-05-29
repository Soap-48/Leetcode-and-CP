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
    int a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,1e7));
    for(int i=0;i<=min(a,b);i+=1)
        dp[i][i]=0;
    for(int i=1;i<=a;i+=1){
        for(int j=1;j<=b;j+=1){
            if(i!=j){
                for(int y=1;y<j;y+=1)
                    dp[i][j]=min(dp[i][j],dp[i][y]+dp[i][j-y]);
                for(int x=1;x<i;x+=1)
                    dp[i][j]=min(dp[i][j],dp[x][j]+dp[i-x][j]);
                dp[i][j]+=1;
            }
        }
    }
    cout<<dp[a][b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}
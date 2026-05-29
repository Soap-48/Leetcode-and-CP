#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int MOD = 1000000007;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    cin>>a>>b;
    int n=a.length(),m=b.length();
    if(m>n) {swap(a,b);swap(n,m);}
    vector<vector<int>> dp(m+1,vi(n+1,1e7));
    for(int i=0;i<=m;i+=1)
        dp[i][0]=i;
    for(int j=0;j<=n;j+=1)
        dp[0][j]=j;
    for(int i=1;i<=m;i+=1){
        for(int j=1;j<=n;j+=1){
            dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+(a[j-1]!=b[i-1])});
        }
    }
    cout<<dp[m][n];
    return 0;
}
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
    int n;
    cin>>n;
    char grid[n][n];
    for(int i=0;i<n;i+=1)
        for(int j=0;j<n;j+=1)
            cin>>grid[i][j];
    vector<vll> dp(n,vll(n,0));
    dp[0][0]=1;
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n;j+=1){
            if(grid[i][j]=='*')
                dp[i][j]=0;
            else{
                if(i==0&&j>0)
                    dp[i][j]=dp[i][j-1];
                else if(j==0&&i>0)
                    dp[i][j]=dp[i-1][j];
                else if(i>0&&j>0){
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
                }
            }
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}
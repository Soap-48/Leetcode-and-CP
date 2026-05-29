#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

/*
dp[i for indice][j for activity (0,1,2)] represent happiness on day i just before perfoming task j
dp[i+1][(0,1,2)-{j}]=max(same cheez,dp[i][j]+h[i][j])
*/

ll dp[100001][3];
ll h[100000][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i+=1)
        cin>>h[i][0]>>h[i][1]>>h[i][2];
    for(int i=0;i<n;i+=1){
        for(int j=0;j<3;j+=1){
            dp[i+1][(j+1)%3]=max(dp[i+1][(j+1)%3],dp[i][j]+h[i][j]);
            dp[i+1][(j+2)%3]=max(dp[i+1][(j+2)%3],dp[i][j]+h[i][j]);
        }
    }
    cout<<max({dp[n][0],dp[n][1],dp[n][2]});
    return 0;
}
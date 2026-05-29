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
    int N,W;
    cin>>N>>W;
    vector<pair<int,int>> a(N);
    ll sum=0;
    for(int i=0;i<N;i+=1){
        cin>>a[i].first>>a[i].second;
        sum+=a[i].second;
    }
    vector<vector<ll>> dp(N+1,vector<ll>(sum+1,1e15));
    dp[0][0]=0;
    for(int i=0;i<N;i+=1){
        for(int j=0;j<=sum;j+=1){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            if(dp[i][j]+a[i].first<=W && j+a[i].second<=sum)
                dp[i+1][j+a[i].second]=min(dp[i+1][j+a[i].second],dp[i][j]+a[i].first);
        }
    }
    for(int i=sum;i>=0;i-=1)
        if(dp[N][i]<=W){
            cout<<i;
            break;
        }
    return 0;
}
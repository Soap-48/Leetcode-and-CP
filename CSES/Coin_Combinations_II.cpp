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
    int n,x;
    cin>>n>>x;
    vector<ll> dp(x+1,0);
    int c[n];
    for(int i=0;i<n;i+=1)
        cin>>c[i];
    sort(c,c+n);
    dp[0]=1;
    for(int i=0;i<n;i+=1){
        for(int j=0;j<=(x-c[i]);j+=1){
            dp[j+c[i]]=(dp[j+c[i]]+dp[j])%1000000007;
        }            
    }
    cout<<dp[x];
    return 0;
}
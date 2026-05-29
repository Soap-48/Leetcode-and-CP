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
    int dp[x+1];
    int c[n];
    for(int i=0;i<n;i+=1)
        cin>>c[i];
    sort(c,c+n);
    dp[0]=1;
    for(int i=1;i<=x;i+=1){
        dp[i]=0;
        for(int j=0;j<n;j+=1)
            if(i>=c[j]) dp[i]=(dp[i]+dp[i-c[j]])%1000000007;
            else break;
    }
    cout<<dp[x];
    return 0;
}
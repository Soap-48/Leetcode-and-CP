#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

int n,k;

ll calc(vector<vector<ll>> &dp,vector<vi> &factors,int a,int b){
    if(a<=0)    return 1;
    else if(dp[a][b]!=-1)
        return dp[a][b];
    else{
        ll res=0;
        for(auto i:factors[b]){
            res=(res+calc(dp,factors,a-1,i))%1000000007;
        }
        dp[a][b]=res;
        return dp[a][b];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        cin>>n>>k;
        vector<vi> factors(n+1);
        for(int i=1;i<=n;i+=1)
            for(int j=1;j*j<=i;j+=1)
                if(i%j==0){
                    factors[i].push_back(j);
                    if(j*j!=i)  factors[i].push_back(i/j);
                }
//dp[k][n]
        vector<vector<ll>> dp(k,vector<ll>(n+1,-1)); 
        // for(int i=1;i<=n;i+=1)
        //     dp[0][i]=1;
        ll ans=0;
        for(int i=1;i<=n;i+=1){
            ans=(ans+calc(dp,factors,k-1,i))%1000000007;
        }
        cout<<ans<<"\n";
    return 0;
}
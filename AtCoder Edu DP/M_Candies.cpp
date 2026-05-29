#include <bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;

int main() {
	// your code goes here
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    vector<long long> dp(k+1,0);
    dp[0]=1;
    for(int i=0;i<n;i+=1){
        vector<long long> ndp(k+1);
        long long val=0;
        for(int j=0;j<=a[i];j+=1){
            val=(val+dp[j])%MOD;
            ndp[j]=val;
        }
        for(int j=a[i]+1;j<=k;j+=1){
            val=(val+dp[j])%MOD;
            val=((val-dp[j-a[i]-1])%MOD+MOD)%MOD;
            ndp[j]=val;
        }
        dp=ndp;
    }
    cout<<dp[k];
    return 0;
}


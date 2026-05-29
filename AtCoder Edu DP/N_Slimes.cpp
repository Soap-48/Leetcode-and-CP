#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    vector<long long> p(n+1);
    p[0]=0;
    for(int i=0;i<n;i+=1)
        p[i+1]=p[i]+a[i];
    vector<vector<long long>> dp(n,vector<long long>(n,1e17));
    for(int i=0;i<n;i+=1)
        dp[i][i]=0;
    // for(int i=1;i<n;i+=1)
    //     dp[i-1][i]=a[i-1]+a[i];
    for(int l=1;l<=n;l+=1)
        for(int i=0;i+l<n;i+=1){
            for(int j=i+1;j<=i+l;j+=1)
                dp[i][i+l]=min(dp[i][i+l],dp[i][j-1]+dp[j][i+l]);
            dp[i][i+l]+=p[i+l+1]-p[i];
        }
    cout<<dp[0][n-1];
    return 0;
}


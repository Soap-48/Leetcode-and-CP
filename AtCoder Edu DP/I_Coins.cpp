#include <bits/stdc++.h>
using namespace std;

double binpow(double b, int p){
    double res=1;
    while(p>0){
        if(p&1)
            res=res*b;
        b=b*b;
        p=p>>1;
    }
    return res;
}

int main() {
	// your code goes here
    int n;
    cin>>n;
    vector<double> p(n);
    for(int i=0;i<n;i+=1)
        cin>>p[i];
    vector<double> dp(n+1,0);
    dp[0]=1-p[0];
    dp[1]=p[0];
    for(int i=1;i<n;i+=1){
        for(int j=i+1;j>=0;j-=1){
            dp[j]=dp[j]*(1-p[i]);
            if(j>0) dp[j]+=dp[j-1]*p[i];
        }
    }
    double ans=0;
    for(int i=(n/2)+1;i<=n;i+=1)
        ans+=dp[i];
    cout<< std::fixed << std::setprecision(10)<<ans;
}


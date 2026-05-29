#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int MOD = 1000000007;
using namespace std;

int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        int n;
        cin>>n;
        vi a(n);
        dp[0]=1;
        int sum=0;
        for(int i=0;i<n;i+=1){
            cin>>a[i];sum+=a[i];
        }
        for(int i=0;i<n;i+=1){
            for(int j=sum;j>=a[i];j-=1)
                if(dp[j-a[i]]) dp[j]=1;
        }
        vi ans(sum);
        int it=0;
        for(int i=1;i<=sum;i+=1)
            if(dp[i])   ans[it++]=i;
        cout<<it<<"\n";
        for(int k=0;k<it;k+=1) cout<<ans[k]<<" ";
    return 0;
}
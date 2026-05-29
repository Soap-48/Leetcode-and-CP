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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi dist(n+1,0);
        vi last(n+1,0);
        vi ans(n+1,1e7);
        int k;
        for(int i=1;i<=n;i+=1){
            cin>>k;
            dist[k]=max(dist[k],i-last[k]);
            last[k]=i;
        }
        for(int i=1;i<=n;i+=1){
            dist[i]=max(dist[i],n+1-last[i]);
            if(dist[i]<=n) ans[dist[i]]=min(ans[dist[i]],i);
        }
        for(int i=1;i<=n;i+=1){
            ans[i]=min(ans[i],ans[i-1]);
            if(ans[i]>=1e7) cout<<"-1 ";
            else cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
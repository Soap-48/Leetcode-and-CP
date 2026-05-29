#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
//#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll ans=0;
    vi vis(k,0);
    for(int i=0;i<k;i+=1){
        if(vis[i]==0){
            vll fr(26,0);
            vis[i]=1;
            for(int j=i;j<n;j+=k){
                fr[s[j]-'a']+=1;
            }
            if((k-1)!=(2*i)){
                vis[k-i-1]=1;
                for(int j=n-i-1;j>=0;j-=k){
                    fr[s[j]-'a']+=1;
                }
            }
            ll mx=0,sum=0;
            for(int j=0;j<26;j+=1){
                sum+=fr[j];
                mx=max(mx,fr[j]);
            }
            ans+=(sum-mx);
        }
    }  
    cout<<ans<<"\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
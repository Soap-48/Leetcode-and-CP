#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vll a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    ll ans=0;
    // for(int i=0;i<n;i+=1){
    //     int c=k;
    //     int last=a[i];
    //     for(int j=i-1;j>=0;j-=1){
    //         int cc=last+1-a[j];
    //         if(cc>0&&cc<=c){
    //             last+=1;
    //             c-=cc;
    //         }
    //         else break;
    //     }
    //     //cerr<<i+1<<'|'<<last<<endl;
    //     ans=max(ans,last);
    // }
    // cout<<ans;nl;
    ll ma=0;
    for(int i=0;i<n;i+=1){
        ans=max(ans,a[i]);
        vll b=a;
        if(a[i]+i>ma){
            ma=a[i]+i;
            ll l=1,k2=k;
            for(int j=i-1;j>=0&&k2>0;j-=1,l+=1){
                ll maxi=k2/l;
                if(b[j]-l+maxi<=b[i]){
                    ans=max(ans,b[j]+maxi);
                }
                else{
                    ans=max(ans,b[i]+l);
                }
                if(j>=1){
                    ll inc=b[j-1]-1-b[j];
                    if(inc>=0){
                        k2-=(inc*l);
                    }
                    else{
                        b[j-1]=b[j]+1;
                        k2+=(inc);
                    }
                }
            }
        }
    }
    cout<<ans;nl;
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
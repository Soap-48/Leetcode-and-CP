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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++)    cin>>a[i];
        ll ans=0;
        for(ll i=29;i>=0;--i){
            vector<ll> cm;
            ll val=(1<<i),count=0;
            for(auto k:a){
                if(val&k)  count++;
                else cm.push_back(k);
            }
            if(count>1ll) ans+=(count*(count-1ll)/2ll);
            a=cm;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
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
        ll n,k;
        cin>>n>>k;
        vector<ll> a(n);
        for(int i=0;i<n;i+=1)
            cin>>a[i];
        map<int,ll> anss;
        anss[0]=0;
        for(int i=0;i<n;i+=1){
            if(a[i]%k!=0){
                if(anss.find(a[i]%k)==anss.end()){
                    anss[a[i]%k]=(k-(a[i]%k))+1;
                }
                else anss[a[i]%k]+=k;
            }
        }
        ll ans=0;
        for(auto i:anss)
            ans=max(ans,i.second);
        cout<<ans<<"\n";
    }
    return 0;
}
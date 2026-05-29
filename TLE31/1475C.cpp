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
        ll a,c,k;
        cin>>a>>c>>k;
        vi boy(k),gril(k);
        for(int i=0;i<k;i+=1)
            cin>>boy[i];
        for(int i=0;i<k;i+=1)
            cin>>gril[i];
        vector<int> b(a,0),g(c,0);
        for(int i=0;i<k;i+=1)
            b[boy[i]-1]+=1;
        for(int i=0;i<k;i+=1)
            g[gril[i]-1]+=1;
        ll ans=k*(k-1)/2;
        for(int i=0;i<a;i+=1)
            ans-=((b[i]*1LL)*(b[i]-1LL)/2LL);
        for(int i=0;i<c;i+=1)
            ans-=((g[i]*1LL)*(g[i]-1LL)/2LL);
        cout<<ans<<"\n"; 
    }
    return 0;
}
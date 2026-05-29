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
        int n,m;
        cin>>n>>m;
        vector<ll>  a(n),b(n);
        a[0]=1;
        for(int i=1;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(all(a));sort(all(b));
        bool cross=false;
        ll ita=0,itb=0;
        ll ans=0;
        while(itb<n)
        {
            ll op=0;
            for(int i=0;i<n-op;++i){
                if(a[i]>=b[i+op]){
                    op++;--i;
                }
            }
            itb=ita+op;
            if(ita>=n-op) {
                ans+=(op*(m-a[ita]+1));
                break;
            }
            else if(m<b[itb]){
               // cout<<m<<"|"<<ita<<"|"<<a[ita]<<"|"<<op<<endl;
                ans+=(op*(m-a[ita]+1));
                break;
            }
            else{
                ans+=(op*(b[itb]-a[ita]));
            a[ita]=b[itb];}
            while(ita<n-1&&a[ita]>a[ita+1]){
                swap(a[ita],a[ita+1]);
                ++ita;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
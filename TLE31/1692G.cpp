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
        int n,k;
        cin>>n>>k;
        vi a(n);
        for(int i=0;i<n;++i)    cin>>a[i];
        int l=-1,r=0;
        ll ans=0;
        for(int i=0;i<n-1;++i){
            if(a[i]<2*a[i+1]){
                if(l==-1){
                    l=i;
                }
                r=i+1;
            }
            else{
                if(l!=-1){
                  if(r-l>=k)  ans+=(r-l+1)-k;
                    l=-1;r=-1;
                }
            }
        }
        if(l!=-1&&r-l>=k)   ans+=(r-l+1)-k;
        cout<<ans<<"\n";
    }
    return 0;
}
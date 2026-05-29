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
        vector<ll> a(n);
        for(int i=0;i<n;i++)    cin>>a[i];
        if(k>=3){
            cout<<"0\n";
        }
        else if(k==1){
            sort(all(a));
            ll mi=a[0];
            for(int i=1;i<n;i++){
                ll val=a[i]-a[i-1];
                mi=min(mi,val);
            }
            cout<<mi<<"\n";
        }
        else{
            sort(all(a));ll mi=a[0];
            for(int i=1;i<n;i++){
                ll val=a[i]-a[i-1];
                mi=min(mi,val);
            }
            if(mi==0){
                cout<<"0\n";
            }
            else{
                for(int i=0;i<n;i++){
                    for(int j=i+1;j<n;j++){
                        ll val1=a[j]-a[i];
                        auto it=lower_bound(all(a),val1);
                        ll n1=1e18+1,n2=1e18+1;
                        if(it!=a.end()) n1=(*it)-val1;
                        --it;
                        if(it>=a.begin()) n2=val1-(*(it));
                        if(n1<mi)mi=n1;
                        if(n2<mi) mi=n2;
                    }
                }
                cout<<mi<<"\n";
            }
        }
    }
    return 0;
}
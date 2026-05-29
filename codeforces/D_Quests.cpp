#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

ll n,c,d;

bool works(ll k,vector<ll> &p){
    ll z=d/(k+1);
    ll val=p[min(k,n-1)]*z;
    if(d%(k+1)){
        val+=p[min((d%(k+1)),n)-1];
    }
    if(val>=c)  return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>c>>d;
        vector<ll> a(n);
        for(int i=0;i<n;i+=1)
            cin>>a[i];
        sort(rall(a));
        vector<ll> p(n);
        p[0]=a[0];
        for(int i=1;i<n;i+=1)
            p[i]=p[i-1]+a[i];
        if(d*a[0]<c){
            cout<<"Impossible\n";
        }

        else if(p[min(d,n)-1]>=c){
            cout<<"Infinity\n";
        }
        else{
            ll lo=0,hi=d-1,ans=-1;
            while (lo<=hi) {
                ll k=(lo+hi)/2;
                if (works(k,p)) {
                    ans=k;
                    lo=k+1;
                }
                else{
                    hi=k-1;
                }
            }
            if(ans>=0)
            cout<<ans<<"\n";
            else{
                cout<<"Impossible\n";
            }
        }

    }
    return 0;
}
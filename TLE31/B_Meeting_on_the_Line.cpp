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
    int n;
    cin>>n;
    vector<double> x(n),t(n);
    for(int i=0;i<n;i+=1)
        cin>>x[i];
    for(int i=0;i<n;i+=1)
        cin>>t[i];
    double l=(*max_element(all(t)))-1.0,r=2.0+l+*max_element(all(x));
    // for(int i=0;i<n;i+=1)
    //     r=max(r,x[i]+t[i]);
    double al=0,ar=1e9;
    while(r-l>=0.0000001){
        double mid=(l+r)/2.0;
        double le=0,re=1e9;
        for(int i=0;i<n;i+=1){
            le=max(le,x[i]-mid+t[i]);
            re=min(re,x[i]+mid-t[i]);
        }
        if(le<=re){
            r=mid;
            al=le;ar=re;
        }
        else
        l=mid;
    }
    cout<<fixed<<setprecision(7)<<(al+ar)/2;nl;
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
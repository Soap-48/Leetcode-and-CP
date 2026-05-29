#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int MOD = 1000000007;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vll x(n),y(n);
        for(int i=0;i<n;i+=1){
            cin>>x[i]>>y[i];
        }
        sort(all(x));sort(all(y));
        ll ax,ay;
        if(n&1){
            ax=1ll;ay=1ll;
        }
        else{
            ax=x[(n/2)]-x[(n/2)-1]+1ll;
            ay=y[(n/2)]-y[(n/2)-1]+1ll;
        }
        cout<<ax*ay<<"\n";
    }
    return 0;
}
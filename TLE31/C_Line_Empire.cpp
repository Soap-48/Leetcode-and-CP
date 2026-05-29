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
        ll n,a,c;
        cin>>n>>a>>c;
        ll cost=0;
        ll pos=0;
        ll k,left=(a/c);
        for(int i=0;i<n;i+=1){
            cin>>k;
            cost+=(c*(k-pos));
            if((n-i-1)>left){
                cost+=(a*(k-pos));
                pos=k;
            }
        }
        cout<<cost<<"\n";
    }
    return 0;
}
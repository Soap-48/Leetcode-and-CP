#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vi a(n+1);
//     map<int,int> m;
//     for(int i=1;i<=k;i+=1){
//         cout<<"? "<<i<<endl;
//         cin>>a[i];m[a[i]]+=1;
//     }
//     // for(int i=k+1;i<=n;i+=1)
//     //     a[i]=a[i%(k)];
//     ll l=k-1,r=n-k+1;
//     while(r-l>1){
//         ll m=(l+r)/2;
//         cout<<"? "<<m<<endl;
//         ll t,t2;
//         cin>>t;
//         if(m%k==0)
//             t2=a[k];
//         else t2=a[m%k];
//         if(t==t2){
//             l=m;
//         }
//         else r=m;
//     }
//     if(l>k&&l+k<=n) {
//         //cerr<<"checking";
//         ll z,zz;
//         cout<<"? "<<l+k<<endl;
//         cin>>z;
//         cout<<"? "<<l<<endl;
//         cin>>zz;
//         // if(l%k==0)  zz=a[k];
//         // else zz=a[l%k];
//         if(z==zz)   {
//             cout<<"! -1"<<endl;return;
//         }
//     }
//     cout<<"! "<<l<<" "<<n-l<<endl;
// }

void solve(){
    ll n,k;
    cin>>n>>k;
    vi a(n+1);
    for(int i=1;i<=k;i+=1){
        cout<<"? "<<i<<endl;
        cin>>a[i];
    }

}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
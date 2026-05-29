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
    int mid=(n+1)/2;
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i],a[i]=abs(a[i]);
    int k=a[0];
    sort(all(a));
    int it=find(all(a),k)-a.begin()+1;
    if(it<=1+((n)/2))
        cout<<"YES\n";
    else cout<<"NO\n";    
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
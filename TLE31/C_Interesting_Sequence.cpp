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
    ll n,x;
    cin>>n>>x;
    if(x>n){
        cout<<"-1\n";
        return;
    }
    if(x==n){
        cout<<n<<'\n';
        return;
    }
    vi a(61,0),b(61,0),c(61,0);
    for(int i=0;i<=60;i+=1){
        a[i]=(n>>i)&1ll;
        b[i]=(x>>i)&1ll;
    }
    for(int i=60;i>=0;i-=1){
        if(a[i]==b[i])  c[i]=a[i];
        else{
            if(a[i]==0&&b[i]==1){
                cout<<"-1\n";
                return;
            }
            else{
                if(b[i+1]==1){
                    cout<<"-1\n";
                    return;
                }
                c[i+1]=1;
                while(i>=0){
                    if(b[i]!=0){
                        cout<<"-1\n";
                        return;
                    }
                    i-=1;
                }
                break;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=60;i+=1)
        if(c[i])    ans+=(1ll<<i);
    cout<<ans;nl;
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
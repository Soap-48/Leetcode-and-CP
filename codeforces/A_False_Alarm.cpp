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
    int n,x;
    cin>>n>>x;
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    int c=x-1;bool flag=false;
    for(int i=0;i<n;i+=1){
        if(flag&&c>0){
            c-=1;
        }
        else if(a[i]==1){
            if(!flag){
                flag=true;
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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
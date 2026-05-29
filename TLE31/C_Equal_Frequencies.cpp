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
    string s;
    cin>>s;
    vi f(26,0);
    for(char c:s)
        f[c-'a']+=1;
    ll ans=0;string ss=s;
    for(int i=1;i<=26;i+=1){
        if(n%i==0){
            int tar=n/i;
            vector<pair<int,char>> aa;
            for(int j=0;j<26;j+=1){
                    aa.push_back({abs(tar-f[j]),j+'a'});
            }
            sort(all(aa));

        }
    }
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
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
    string s;ll pos;
    cin>>s;
    cin>>pos;
    ll n=s.size();
    ll l=-1,r=n;
    while(r-l>1){
        ll i=(l+r)/2;
        ll val=((2*n-i+1)*(i))/2;
        if(val<pos)
            l=i;
        else
            r=i;
    }
    //cerr<<l<<'\n';
    ll p=pos-(((2*n-l+1)*(l))/2);
    string ans="";
    int left=l;
    multiset<char> ss(s.begin(),s.begin()+l+1);
    int i=0;
    while(i<n&&left>0){
        if(s[i]==(*ss.begin())){
            ans+=s[i];
            if(i+left+1<n)    ss.insert(s[i+left+1]);
        }
        else{
            left-=1;
        }
        ss.extract(s[i]);
        i+=1;
    }

    if(i<n){
        while(i<n){
            ans+=s[i];
            i+=1;
        }
    }
   // cerr<<ans<<"\n";
    cout<<ans[p-1];
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
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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<n;i+=1){
        if(s[i]=='0')   a+=1;
        else b+=1;
    }
    if(n%2==0){
        ll aa=a-(n-2*k)/2,bb=b-(n-2*k)/2;
        if(aa>=0&&bb>=0&&aa%2==0&&bb%2==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    else{
        ll aa=a-(n-2*k-1)/2,bb=b-(n-2*k-1)/2;
        if(aa>=0&&bb>=0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
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
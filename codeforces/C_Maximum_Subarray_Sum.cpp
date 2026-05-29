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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vll a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    bool chan=false;
    ll sum=0,maxi=0;
    int fi=1e6;
    for(int i=0;i<n;i+=1){
        if(s[i]=='1'){
            sum+=a[i];
            maxi=max(maxi,sum);
            if(sum<0)   sum=0;
        }
        else{
            sum=0;
            fi=min(fi,i);
            chan=true;
        }
    }
    if(maxi>k){
        cout<<"No\n";return;
    }
    if(maxi==k){
        cout<<"Yes\n";
        for(int i=0;i<n;i+=1){
            if(s[i]=='1')   cout<<a[i]<<' ';
            else cout<<-((ll)1e17)<<' ';
        }
        nl;
        return;
    }
    if(!chan){
        cout<<"No\n";return;
    }
    cout<<"Yes\n";
    ll s1=0,s2=0,run=0;
    for(int j=fi+1;j<n&&s[j]=='1';j+=1){
        run+=a[j];
        s2=max(s2,run);
    }
    run=0;
    for(int j=fi-1;j>=0&&s[j]=='1';j-=1){
        run+=a[j];
        s1=max(s1,run);
    }
    a[fi]=k-s1-s2;
    s[fi]='1';
    for(int i=0;i<n;i+=1){
        if(s[i]=='1')   cout<<a[i]<<' ';
        else cout<<-((ll)1e17)<<' ';
    }
    nl;
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
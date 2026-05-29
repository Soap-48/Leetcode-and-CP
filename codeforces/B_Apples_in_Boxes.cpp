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
    vll a(n);
    ll sum=0;
    for(int i=0;i<n;i+=1)
        cin>>a[i],sum+=a[i];
    ll ma=(*max_element(all(a))),mi=(*min_element(all(a)));
    int flag=0;
    for(int i=0;i<n;i+=1)
        if(a[i]==ma)    flag+=1;
    if(ma-mi-1+(flag>1)>k){
        cout<<"Jerry\n";
    }
    else{
        if((sum)&1){
            cout<<"Tom\n";
        }
        else{
            cout<<"Jerry\n";
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

/*
Foolish Mistake forgot about case where array has multiple entries that are maximiun, ex -1 2 3 3
*/
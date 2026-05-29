#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll n,dummy;
        cin>>n;
        ll k=2;
        bool flag=true;
        for(;k*k<=n;k++){
            if((n-1)%k==0){
            ll o=(n*(k-1))+1;
            ll x=1;
            while(x<o){
            x=x*k;
            }
            if(x==o)    {cout<<"YES\n";flag=false;break;}
            }
        }
        if(flag){cout<<"NO\n";}
    
    }
    return 0;
}
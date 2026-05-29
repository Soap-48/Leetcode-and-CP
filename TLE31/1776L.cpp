#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll p=0,m=0;
    for(char &c:s)
        if(c=='+')  p+=1;
        else m+=1;
    ll c=p+m;
    p=min(p,m);
    m=c-p;
    ll a,b;
    int q;
    cin>>q;
    for(ll i=0;i<q;i+=1){
        cin>>a>>b;
        ll z=a+b;
        a=max(a,b);b=z-a;
        ll d=gcd(a,b);
        ll x=b/d,y=a/d;
    if(a==b){
        if(m==p)    cout<<"YES\n";
        else cout<<"NO\n";
    }
    else if((m-p)%(y-x)==0) {
        int k=(m-p)/(y-x);
        if(p-k*x>=0&&m-k*y>=0)  cout<<"YES\n";
        else cout<<"NO\n";
    }
    else cout<<"NO\n";
    }
    return 0;
}
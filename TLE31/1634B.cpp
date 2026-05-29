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
    int t;
    cin>>t;
    while(t--){
        ll n,x,y,tt;
        cin>>n>>x>>y;
        ll pa=0;
        for(int i=0;i<n;++i){
            cin>>tt;
            pa+=(tt%2);
        }
        x=(x+pa)%2;
        y=y%2;
        if(x==y)    cout<<"Alice\n";
        else        cout<<"Bob\n";
    }
    return 0;
}
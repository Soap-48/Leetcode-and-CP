#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<string> s{string("0"),string("1")};
    while(--n){
        ll t=s.size();
        for(int k=t-1;k>=0;k--)
            s.pb(s[k]);
        for(int k=0;k<t;k++)
            s[k].append("0");
        ll tt=s.size();
        for(int k=t;k<tt;k++)
            s[k].append("1");
    }
    for(auto q:s)
        cout<<q<<'\n';
    return 0;
}
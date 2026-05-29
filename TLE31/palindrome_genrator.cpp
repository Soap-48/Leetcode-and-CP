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
    ll c=0;
    for(ll i=1;i<(4*1e4);i+=1){
        string s=to_string(i);
        string t=s;
        reverse(all(t));
        if(s==t){
            cout<<i<<",";
            c+=1;
        }
    }
            cout<<endl<<c;
    return 0;
}
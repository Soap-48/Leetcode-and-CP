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
    int n,s;
    cin>>n>>s;
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    int b=*max_element(all(a)),c=*min_element(all(a));
    if(s>=c&&s<=b)  cout<<b-c+min(s-c,b-s);
    else if(s<c)    cout<<b-s;
    else if(s>b)    cout<<s-c;
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
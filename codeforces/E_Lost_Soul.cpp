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
    int n;
    cin>>n;
    vi a(n),b(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    for(int i=0;i<n;i+=1)
        cin>>b[i];
    // set<int> s[2]; //first indice flips with indice in array 1,...,n second idice flips with a or b
    multiset<int> s;
    if(a[n-1]==b[n-1]){
        cout<<n;nl;return;
    }
    s.insert(a[n-1]);s.insert(b[n-1]);
    for(int i=n-2;i>=0;i-=1){
        if(a[i]==b[i]||a[i]==a[i+1]||b[i]==b[i+1]){
            cout<<i+1;nl;return;
        }
        if(s.count(a[i])>=1){
            if(a[i]==b[i+1]){
                if(s.count(a[i])>=2){
                    cout<<i+1;nl;return;
                }
            }
            else{
                cout<<i+1;nl;return;
            }
        }
        if(s.count(b[i])>=1){
            if(b[i]==a[i+1]){
                if(s.count(b[i])>=2){
                    cout<<i+1;nl;return;
                }
            }
            else{
                cout<<i+1;nl;return;
            }
        }
        s.insert(a[i]);s.insert(b[i]);
    }
    cout<<"0\n";return;
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
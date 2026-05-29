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
    for(int j=30;j>=0;j-=1){
        int sum=0;
        int last=-1;
        for(int i=0;i<n;i+=1){
            int p=(a[i]>>j)&1;
            int q=(b[i]>>j)&1;
            sum+=(p+q);
            if(p+q==1){
                if(i&1)
                    last=1;
                else
                    last=0;
            }
        }
        if(sum&1){
            if(last!=-1){
                if(last)
                    cout<<"Mai\n";
                else
                    cout<<"Ajisai\n";
                return;
            }
        }
    }
    cout<<"Tie\n";
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
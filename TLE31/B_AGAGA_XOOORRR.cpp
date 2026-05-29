#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int MOD = 1000000007;
using namespace std;

void solve(){
    int n;
        cin>>n;
        vll px(n+1);
        px[0]=0ll;
        ll x;
        for(int i=1;i<=n;i+=1){
            cin>>x;
            px[i]=px[i-1]^x;
        }
        if(px[n]==0){

                    cout<<"YES\n";
                    return;
        }
        if(n>=3){
            for(int i=1;i<n;i+=1){
                if(px[n]==px[i]){
                    for(int j=i+1;j<n;j+=1){
                        if(px[n]==(px[j]^px[i])){
                            cout<<"YES\n";
                            return;
                        }
                    }
                }
            }
        }
        cout<<"NO\n";
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
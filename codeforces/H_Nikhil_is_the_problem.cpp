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
    ll in;
    ll constant = 10000000000000000ll;
    ll cons2= 100000000000000000ll;
    cout<<"? 10000000000000000 10000000000000000"<<endl;
    cin>>in;
    if(in==constant){
        cout<<"! 0"<<endl;
        cin>>in;
        return;
    }
    else{
        ll curr=1;
        ll a=1,b=2;
        ll la=a,lb=b;
        ll w=0;
        for(int i=1;i<=55;i+=1){
            curr*=2ll;
            la=a;lb=b;
            if(curr>=cons2){
                break;
            }
            cout<<"? "<<a<<" "<<curr<<endl;
            cin>>in;
            if(in==-1){
                return;
            }
            //cerr<<"LOG: "<<curr<<"*n-";
            if(in==curr){
                w=1;
               // cerr<<a<<endl;
                b=a+curr;
            }
            else{
               // cerr<<b<<endl;
                a=b;
                b+=curr;
                w=2;
            }
            //cerr<<"curr:"<<curr;
            //cerr<<" a:"<<la<<" b:"<<lb<<endl;;
        }
        if(w==1) cout<<"! "<<(curr-la)<<endl;
        else    cout<<"! "<<(curr-lb)<<endl;
        cin>>in;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
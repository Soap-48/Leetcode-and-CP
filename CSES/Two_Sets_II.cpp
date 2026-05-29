#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int MOD = 1000000007;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    if(n%4==1||n%4==2){
        cout<<"0\n";
    }
    else{
        ll val=(n*(n+1))/2;
        vector<vll> a(2,vll(((n*(n+1))/2)+1,0));
        a[1][1]=1;
        ll curr=2;
        int in=0;
        while(curr<=n){
            for(int i=0;i<=val;i+=1)
                a[in][i]=0;
            for(int i=0;i<=val-curr;i+=1)
                a[in][i+curr]=a[1-in][i];
            for(int i=0;i<=val;i+=1)
                a[in][abs(i-curr)]=(a[in][abs(i-curr)]+a[1-in][i])%MOD;

            // cerr<<"curr: "<<curr<<" in: "<<in<<endl;
            // for(int i=0;i<=val;i+=1)
            //     cerr<<a[in][i]<<" ";
            // cerr<<endl;
            // for(int i=0;i<=val;i+=1)
            //     cerr<<a[1-in][i]<<" ";
            // cerr<<endl;
            curr+=1;
            in=1-in;
        }
        cout<<a[1-in][0]<<"\n";
    }
    return 0;
}
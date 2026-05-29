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
        ll k;
        cin>>k;
        int l=0,r=14;
        ll mid,m;
        while(l<=r){
            if(l==r) break;
            mid=1;
            m=(l+r)/2;
            while(m>0){
                mid*=10;--m;
            }
            m=(l+r)/2;
            mid=((mid*(9ll*m+1ll)-1ll)/9ll)-1ll;
            if(k==mid){ 
                break; }
            else if(k>mid) {
                l=m+1;}
            else if(k<mid) {
                r=m-1;}
        }
        ll x=k-mid;
        ll ans=1,temp=m;
        while(temp>0){
                ans*=10;--temp;
        }
        ll fno=ans-1;
        ans=ans/10;
        ans=ans*45*m;
        fno+=(x/(m+1));
        //cout<<m<<"|"<<l<<"|"<<r<<endl;
        cout<<ans<<"|"<<x<<"\n";
    }
    return 0;
}
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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vll a(n);
        for(int i=0;i<n;i+=1)
            cin>>a[i];
        // ll prev=0,ans=0;
        // for(int i=1;i<n;i+=1){
        //     if(a[i-1]<=a[i]&&prev>0){
        //         ans=max(ans,(ll)(ceil(log2(prev)))+1);
        //         prev=0;
        //     }   
        //     else{
        //         prev+=(a[i-1]-a[i]);
        //     }
        // } 
        // ans=max(ans,(ll)(ceil(log2(prev))+1));
        // cout<<ans<<"\n";
        ll ans=0;
        for(int i=1;i<n;i+=1){
            if(a[i]<a[i-1]){
                double diff=a[i-1]-a[i]+1;
                ll x=(ll)(ceil(log2(diff)));
                ans=max(ans,x);
                a[i]=a[i-1];
            }
        }
        cout<<ans<<"\n";

    }
    return 0;
}

/*
    A really nice thing about powers of two is 1+2+4+...+2^x is -1+2^x+1.
    also by removing certain indices as required we can achive any number in range [0,-1+2^x+1]
    using only numbers from previous sequence, hence for every number we find the max x+1 we.
    this gives us our time, Also earlier I was just adding -1+2^x to the number after operation
    however since we want non decreasing sequence its best to make my number exactly equal to previous 
    since it need to be as large as previous number but if it can be, smaller than next. hence as small
    as possible.
*/
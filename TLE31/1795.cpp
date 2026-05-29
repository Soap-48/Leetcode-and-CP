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
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<ll> a(n),b(n),pb(n+1);
        for(int i=0;i<n;i+=1)
            cin>>a[i];
        for(int i=0;i<n;i+=1)
            cin>>b[i];
        pb[0]=0;
        for(int i=1;i<=n;i+=1)
            pb[i]=pb[i-1]+b[i-1];
        vector<ll> a1(n,0),a2(n,0);
        for(int i=0;i<n;i+=1){
            auto it=upper_bound(all(pb),a[i]+pb[i]);
            int t=it-pb.begin()-1;
            a1[i]+=1;
            if(t<n) a1.at(t)-=1;
            if(t<n) a2[t]+=a.at(i)+pb.at(i)-pb.at(t);
        }
        for(int i=1;i<n;i+=1)
            a1[i]+=a1[i-1];
        for(int i=0;i<n;i+=1)
            cout<<(a1.at(i)*(b.at(i)*1LL))+a2.at(i)<<" ";
        cout<<"\n";
    }
    return 0;
}
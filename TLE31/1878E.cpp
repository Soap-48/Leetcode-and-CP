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
        int n,q,l,k;
        cin>>n;
        vi a(n+1);
        for(int i=1;i<=n;i++)    cin>>a[i];
        cin>>q;
        vector<vi> b(n+1,vector<int>(31,0));
        for(int i=0;i<31;i++){
            int val=(1<<i);
            for(int j=1;j<=n;++j){
                if(a[j]&val){
                    b[j][i]=b[j-1][i]+1;
                }
                else{
                    b[j][i]=b[j-1][i];
                }
            }
        }
        // for(auto i:b){
        //     for(auto j:i)
        //         cout<<j;
        //     cout<<" ";}
        // cout<<"\n";
        for(int i=0;i<q;i++){
            cin>>l>>k;
            if(a[l]<k)  cout<<"-1 ";
            else{
                int r=n,l2=l,mid,ans=l;
                while(l2<=r){
                    mid=(l2+r)/2;
                    int trm=0;
                    for(int p=0;p<31;++p){
                        if(b[mid][p]-b[l-1][p]>(mid-l)){
                            trm+=(1<<p);
                        }
                    }
                    if(trm>=k){
                        ans=mid;
                        l2=mid+1;
                    }
                    else if(trm<k){
                        r=mid-1;
                    }
                }
                cout<<ans<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
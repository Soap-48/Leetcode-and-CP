#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n+1);
        vector<long long> p(n+1);
        if(n==1){cin>>a[0];cout<<"0\n";}
        else{
        p[0]=0;
        a[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            p[i]=p[i-1]+a[i];
        }
        ll ans=0;
        for(int i=1;i<n;i++){
            if(n%i==0){
                ll sum=0,max=0,min=INFINITY;
                for(int j=i;j<=n;j+=i){
                    sum=p[j]-p[j-i];
                   // cout<<j<<'\n';
                   // cout<<"sum: "<<sum;
                    if(sum>max) max=sum;
                   // cout<<" max: "<<max;
                    if(sum<min) min=sum;
                   // cout<<" min: "<<min<<'\n';
                }
                if(max-min>ans)    ans=max-min;
            }
        }
        cout<<ans<<'\n';
    }
    }
    return 0;
}
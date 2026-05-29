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
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    int ans=INT_MAX,tgcd=a[0],l=0,r=0,cnt=0;
    for(int i=0;i<n;i+=1){
        if(a[i]==1) cnt+=1;
        tgcd=gcd(tgcd,a[i]);
        if(tgcd==1){
            r=i;
            ans=min(ans,n-1+(r-l));
            int k=1;
            while(tgcd==1&&l<i){
                l+=1;
                int ngcd=a[l];
                for(int j=l;j<=i;j+=1){
                    ngcd=gcd(ngcd,a[j]);
                }
                if(ngcd==1){
                    ans=min(ans,n-1-(l-r));
                }
                tgcd=ngcd;
            }
        }

    }
        if(cnt>0)   ans=n-cnt;
        if(l==0&&r==0&&tgcd!=1)   ans=-1;
        cout<<ans<<"\n";    
        return 0;
}
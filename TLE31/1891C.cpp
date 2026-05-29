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
        int n;
        cin>>n;
        vi a(n);
        for(int i=0;i<n;i+=1)
            cin>>a[i];
        sort(all(a));
        ll ans=0,target=a[n-1],ti=n-1,sum=0;
        for(int i=0;i<n;i+=1){
            if(sum<target){
                if(i<ti){
                    if(a[i]+sum>=target){
                    a[ti]=0;n-=1;
                    ans+=(target-sum+1);
                    a[i]-=(target-sum);
                    i-=1;
                    sum=0;
                    ti-=1;
                    target=a[ti];
                }
                else{
                    sum+=a[i];
                    ans+=a[i];
                }
            }
            else{
                ll c=a[i]-sum;
                if(c==1&&sum==0){ans+=1;}
                else{ans+=((c/2)+1);
                if(c%2!=0)  ans+=1;}
                break;
            }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll n1,n2;
        n1=n*(n+1)/2;
        cout<<"2 1 "<<n<<endl;
        cin>>n2;
        ll length=(n2-n1);
        int l=1,r=n,mid,ans;
        while(l<=r){
            mid=(l+r)/2;
            cout<<"1 1 "<<mid<<endl;
            cin>>n1;
            cout<<"2 1 "<<mid<<endl;
            cin>>n2;
            if(n2-n1>=length){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cout<<"! "<<ans-length+1<<" "<<ans<<endl;
    }
    return 0;
}
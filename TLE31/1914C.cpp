#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        unsigned short a[n],b[n],mb[n],max=0;
        unsigned int pa[n];
        cin>>a[0];
        pa[0]=a[0];
        for(int i=1;i<n;i++){
            cin>>a[i];
            pa[i]=pa[i-1]+a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            if(b[i]>max){
                max=b[i];
            }
            mb[i]=max;
        }
        /*for(auto t:a)   cout<<t<<' ';
        cout<<endl;
        for(auto t:pa)   cout<<t<<' ';
        cout<<endl;
        for(auto t:b)   cout<<t<<' ';
        cout<<endl;
        for(auto t:mb)   cout<<t<<' ';
        cout<<endl;*/
        int k2= (k<n)?k:n;
        unsigned long curr,ans=0;
            for(int i=0;i<k2;i++){
                curr=pa[i]+ ((k-i-1)*mb[i]);
                if(curr>ans)    ans=curr;
            }
        cout<<ans<<'\n';
        
    }
    return 0;
}
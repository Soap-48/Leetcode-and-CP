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
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long int sum=0,max=a[0];
        int parity=(abs(a[0])+1)%2;
        for(int i=0;i<n;i++){
            if(abs(a[i])%2!=parity){
            sum=sum+a[i];
            if(sum>max) max=sum;
            if(sum<=0) sum=0;
            parity=((parity)?0:1);
            }
            else{
                sum=a[i];
               if(sum>max) max=sum;
               if(a[i]<0)  sum=0;
            }
        }
        cout<<max<<'\n';
    }
    return 0;
}
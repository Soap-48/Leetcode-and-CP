#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        vi a(n);
        for(int i=0;i<n;i++)    cin>>a[i];
        sort(all(a));
        ll h=a[0],j=1,c=0,prev=a[0];
        ll need=0;
        while(j<n){
            if(a[j]>prev){
                prev=a[j];
                need=(j)*((a[j]-a[j-1])*1LL);
                if(x>=need){
                    x=x-need;
                    h=a[j];                    
                }
                else{
                    h=h+(x/(j));
                    x=0;
                    break;
                }
            }
            j++;
        }
        if(x>0) {h+=(x/n);}
        cout<<h<<'\n';
    }
    return 0;
}
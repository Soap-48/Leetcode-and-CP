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
        string s;
        cin>>s;
        vi pxor(n+1);
        pxor[0]=0;
        for(int i=1;i<=n;i+=1)
            pxor[i]=pxor[i-1]^a[i-1];
        int val=0,txor=pxor[n];
        for(int i=0;i<n;i+=1)
            if(s[i]=='1')   val=val^a[i];
        int q;
        cin>>q;
        int l,r,type,tp;
        for(int i=0;i<q;i+=1){
            cin>>tp;
            if(tp==1){
                cin>>l>>r;
                for(int i=l-1;i<r;i+=1)
                    if(s[i]=='1')   s[i]=='0';
                    else s[i]=='1';
                val=val^(pxor[r]^pxor[l-1]);
            }
            else{
                cin>>type;
                if(type==1){
                    cout<<val<<" ";
                }
                else    cout<<(txor^val)<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
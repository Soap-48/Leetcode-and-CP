#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

ll fact(ll k){
    if(k<=1)    return 1;
    else return (k*fact(k-1))%(1000000007LL);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vi a(n);
        for(int i=0;i<n;++i)
            cin>>a[i];
        int min=a[0];ll count=1;
        for(int i=1;i<n;i+=1)
            if(a[i]<min)
                {min=a[i];count=1;}
            else if(a[i]==min)
                count+=1;
        if(count<2)
            cout<<"0\n";
        else{
            bool flag=true;
            for(int i=0;i<n;i+=1)
                if((a[i]&min)!=min){
                    flag=false;
                    break;
                }
            if(flag){
                ll ans=((count)*(count-1))%1000000007LL;
                ans=ans*(fact((n-2)));
                cout<<(ans%1000000007LL)<<"\n";
            }
            else 
                cout<<"0\n";
        }
    }
    return 0;
}
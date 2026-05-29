#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

int main() {
    vi a(3);
    for(int i=0;i<3;i+=1)
        cin>>a[i];
    sort(rall(a));
    if(a[2]==0)
        a.erase(a.end()-1);
    if(a[1]==0)
        a.erase(a.begin()+1);
    int ans=0;
    while(a.size()>=2&& a.back()>=1){
        cerr<<a[0]<<" "<<a[1]<<" "<<a[2]<<" |";
        int d=min(a[0]/2,a[1]);
        if(d==0){
            if(a.size()>=3)
                ans+=1;
            break;
        }
        ans+=d;
        a[0]-=2*d;
        a[1]-=d;
        if(a[1]==0) 
            a.erase(a.begin()+1);
        if(a[0]==0)
            a.erase(a.begin());
        cerr<<d<<"| "<<a[0]<<" "<<a[1]<<" "<<a[2]<<"| "<<ans<<"\n";
        if(!a.empty())
            sort(rall(a));
    }
    cout<<ans;
    return 0;
}
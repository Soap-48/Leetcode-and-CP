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
        vi h(n);
        for(int i=0;i<n;i++)    {cin>>h[i];}
        int bh=h[k-1], w=1;
        sort(all(h));
        h.erase(unique(all(h)),h.end());
        if(h.size()==1) {cout<<"Yes\n";continue;}
        int hmax=h.back();
        auto i=find(all(h),bh);
        bool flag=true;
        while(bh<hmax){
            i++;
            w=w+(*(i))-bh;
            if(bh<(w-1)){
                cout<<"NO\n";
                flag=false;
                break;
            }
            else{
                bh=*(i);
            }
        }
        if(flag) cout<<"YES\n";
    }
    return 0;
}
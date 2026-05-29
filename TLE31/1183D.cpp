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
        map<int,int> a;
        int temp;
        for(int i=0;i<n;i+=1){
            cin>>temp;
            a[temp]+=1;
        }
        vector<ll> anss;
        for(auto &[i,j]:a)
            anss.push_back(j);
        sort(rall(anss));
        ll ans=0,last=anss[0]+1;
        for(int i=0;i<anss.size();i+=1){
            if(anss[i]<last){
                ans+=anss[i];
                last=anss[i];
            }
            else{
                ans+=(last-1);
                last-=1;
            }
            if(last<=1) break;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
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

        int n;
        cin>>n;
        vector<ll> a1(n),a2(n);
        for(int i=0;i<n;i+=1)
            cin>>a1[i];
        for(int i=0;i<n;i+=1)
            cin>>a2[i];
        vector<ll> ans1(n),ans2(n);
        ans1[0]=a1[0];ans2[0]=a2[0];
        if(n>1){
            ans1[1]=(a2[0]+a1[1]);
            ans2[1]=a1[0]+a2[1];
        }
        for(int i=2;i<n;i+=1){
            ans1[i]=max(ans2[i-1]+a1[i],ans2[i-2]+a1[i]);
            ans2[i]=max(ans1[i-1]+a2[i],ans1[i-2]+a2[i]);
        }
        cout<<max(ans1[n-1],ans2[n-1])<<"\n";
    
    return 0;
}
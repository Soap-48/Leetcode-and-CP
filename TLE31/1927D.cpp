#if defined(__GNUC__)
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#endif

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
        int n;
        cin>>n;
        vi a(n),b(n,0);
        cin>>a[0];
        for(int i=1;i<n;i++){
            cin>>a[i];
            if(a[i]==a[i-1]) b[i]=b[i-1]+1;
        }
        int q;
        cin>>q;
        while(q--){
            int l,r;
            cin>>l>>r;
            if(l>=(r-b[r-1])){
                cout<<"-1 -1\n";
            }
            else {
                cout<<r-b[r-1]-1<<' '<<r<<'\n';
            }
        }
        cout<<'\n';
    }
    return 0;
}

/*
iss question ka simple sa brute force approach bhi hai jo tle dega, aabhi tak aisa lag raha hai ki 1300 wale sawalo mei brute force approach dik ja rahi hai but kucch optimized sochna padta hai
*/
#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int getpow(int x){
    int j=0;
    while((x&(1<<j))==0){
        j++;
    }
    return j;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n,q;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<pair<int,pair<int,int>>> a(n);
        vector<int> b(q),ans(n);
        for(int i=0;i<n;i++){
            cin>>a[i].second.first;
            a[i].second.second=i;
            a[i].first=getpow(a[i].second.first);
        }
        sort(all(a));
        for(int i=0;i<q;i++)    cin>>b[i];
        for(auto i:b){
            int j=n-1;
            while(j>=0){
                if(a[j].first>=i){
                    a[j].second.first+=(1<<(i-1));
                    a[j].first=(i-1);
                    j--;
                }
                else break;
            }
        }
        for(auto i:a){
            ans[i.second.second]=i.second.first;
        }
        for(auto i:ans) cout<<i<<' ';cout<<'\n';
       // for(auto k:a)   cout<<'('<<k.second<<','<<k.first<<")";cout<<endl;
        
    }
    return 0;
}


/*
    instead of sorting the 
*/
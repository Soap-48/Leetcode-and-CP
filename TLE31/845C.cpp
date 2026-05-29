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
    int ctime=0;
    bool tv1=false,tv2=false;
    int tv1f=0,tv2f=0;
    int l,r;
    string ans="YES";
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i+=1){
        cin>>a[i].first>>a[i].second;
    }
    sort(all(a));
    for(int i=0;i<n;i+=1){
    
            l=a[i].first;
            r=a[i].second;
        if(tv1&&l>tv1f) {
            tv1=false;
            tv1f=0;
        }
        if(tv2&&l>tv2f){
            tv2=false;
            tv2f=0;
        }
        if(!tv1){
            tv1=true;
            tv1f=r;
        }
        else if(!tv2){
            tv2=true;
            tv2f=r;
        }
        else {ans="NO";break;}
    
    }
    cout<<ans<<"\n";
    return 0;
}
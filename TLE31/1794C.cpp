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
        vector<int> a(n);
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        int cost=1,s=0;
        cout<<"1 ";
        for(ll i=1;i<n;i++){
            if(a[s]>(cost))   cost+=1;
            else  s=s+1;
            cout<<cost<<' ';
        }
        cout<<"\n";
    }
    return 0;
}
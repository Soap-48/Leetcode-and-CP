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
    int it=1;
    while(it<=n){
        int val=it;
        while(val<=n){
            cout<<val<<' ';
            val=val*2;
        }
        it+=2;
    }
    cout<<"\n";
}
    return 0;
}
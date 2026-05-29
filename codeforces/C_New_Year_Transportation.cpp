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
    int n,t;
    cin>>n>>t;
    vi a(n-1);
    for(int i=0;i<n-1;i+=1)
        cin>>a[i];
    int pos=1;
    bool flag=false;
    while(pos<n){
        if(pos==t){
            flag=true;
            break;
        }
        else{
            pos+=a[pos-1];
        }
    }
    if(pos==t)  flag=true;
    cout<<(flag?"YES":"NO");
    return 0;
}
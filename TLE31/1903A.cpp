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
        int n,k;
        cin>>n>>k;
        if(k>1){cout<<"yes\n";}
        string s="yes";
        int prev=0,curr;
        while(n--){
            cin>>curr;
            if(prev>curr)   {s="no";}
            prev=curr;
        }
        if(k==1){cout<<s<<'\n';}
    }
    return 0;
}
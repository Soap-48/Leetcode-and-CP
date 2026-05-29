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
        bool flag=false;
        int failc=0;
        int fail[3]={1,0,1};
        int k;
        for(int i=2;i<n;i+=1){
            cin>>k;
            if(failc==3) {flag=true;failc=0;}
            else{
                if(fail[failc]==k){
                    failc+=1;
                }
                else{
                    failc=0;
                    if(1==k)  failc+=1;
                }
            }
        }
                    if(failc==3) {flag=true;failc=0;}

        if(flag){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
    return 0;
}
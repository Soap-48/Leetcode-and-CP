#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int l=1,r=(1e6);
    string s,a("<"),b(">=");
    int ans=696969;
    while(l<=r){
        int mid=(l+r)/2;
        cout<<mid<<endl;
        cin>>s;
        if(s==b){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<"! "<<ans;
    return 0;
}
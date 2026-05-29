#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    int n1,n2;
    int a,b;
    while(t--){
        cin>>n1>>n2;
        if(n1==0&&n2==0)    {cout<<"YES\n";continue;}
        if(n1==0||n2==0)    {cout<<"NO\n";continue;}
        a=2*n2-n1;
        b=2*n1-n2;
        if(a<0||b<0)    {cout<<"NO\n";continue;}
        if(a%3==0&&b%3==0)  cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
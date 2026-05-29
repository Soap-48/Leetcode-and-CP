#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int a=n,b=0,k;
    while(--n){
        cin>>k;
        b=b^k;
        a=a^n;
        
    }
    cout<<(a^b);
    return 0;
}
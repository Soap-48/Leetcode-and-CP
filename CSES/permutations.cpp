#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    if(n==1){
        cout<<'1';
        return 0;
    }
    if(n<4) {
        cout<<"NO SOLUTION";
        return 0;
    }
    int k=n;
    if(k%2==0)  k=k-1;
    while(k>=5){
        cout<<k<<' ';
        k=k-2;
    }
    cout<<"2 4 1 3 ";
    k=6;
    while(k<=n){
        cout<<k<<' ';
        k=k+2;
    }
    return 0;
}
#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int n;

void solve(int b1[],int b2[],int b3[],int a){
    if(a==0)    return;
    solve(b1,b3,b2,a-1);
    b3[a-1]=b1[a-1];
    b1[a-1]=0;
    cout<<b1[n]<<' '<<b3[n]<<'\n';
    solve(b2,b1,b3,a-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int bar1[n+1],bar2[n+1],bar3[n+1];
    for(int k=0;k<n;k++){
        bar1[k]=k+1;
        bar2[k]=0;
        bar3[k]=0;
    }
    bar1[n]=1;bar2[n]=2;bar3[n]=3;
    int m=pow(2,n)-1;
    cout<<m<<'\n';
    solve(bar1,bar2,bar3,n);
    return 0;
}
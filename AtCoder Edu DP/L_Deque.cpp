#include <bits/stdc++.h>
using namespace std;

long long x=0,y=0;

// long long dp(vector<vector<long long>> &f,vector<long long> &p,int l int r){
//     if(f[l][r]!=-1)
//         return f[l][r];
    
// }

// long long help(int l,int r,int t){
// }

int main() {
	// your code goes here
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    vector<vector<long long>> f(n,vector<long long>(n,-1));
    for(int i=0;i<n;i+=1)
        f[i][i]=a[i];
    vector<long long> p(n+1,0);
    for(int i=0;i<n;i+=1)    
        p[i+1]=p[i]+a[i];
    for(int l=1;l<n;l+=1)
        for(int i=0;i+l<n;i+=1)
            f[i][l+i]=p[l+i+1]-p[i]-min(f[i][l+i-1],f[i+1][l+i]);
    // int l=0,r=n-1;
    // while(l<r){
    //     x+=f[l][r];
    x=f[0][n-1];
    y=p[n]-x;
    cout<<x-y;
    //help(f,p,l,r,0);
    return 0;
}


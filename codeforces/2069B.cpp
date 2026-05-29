#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
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
        int n,m;
        cin>>n>>m;
        vector<vi> a(n,vi(m));
        for(int i=0;i<n;i+=1)
            for(int j=0;j<m;j+=1)
                cin>>a[i][j];
        vector<vll> c(2,vll(n*m+1,0));
        bool has2=false;
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                c[(i+j)%2][a[i][j]]=c[(i+j)%2][a[i][j]]|1;
            }
        }
        long long sum=0;
        for(int i=1;i<=n*m;i+=1){
            if((c[0][i]+c[1][i])==2)  has2=true;
            sum=sum+c[0][i]+c[1][i];
        }
        if(has2)    sum-=2;
        else sum-=1;
        cout<<sum<<"\n";
    }
    return 0;
}
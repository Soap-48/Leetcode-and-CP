#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;


// takes O(n) to find mex
// need to find for n2 elements
// O(n3) and n3 is aroung 1e6, so okay

//traveser like the perimeter of a square
// i=fix j=0 to i-1 bottom side including corner
// i=0 to j, j=fix left side of square

//uhhh i dont feel like solving

void solve(){
    ll n;
    cin>>n;
    int ma=n*n+1;
    vector<vector<int>> a(n,(vector<int>(n,-1)));
    a[0][0]=0;
    for(int l=2;l<=n;l+=1){
        int i=l-1;
        for(int j=0;j<l-1;j+=1){
            vector<int> t(ma,0);
            // pos i,j
            for(int x=0;x<i;x+=1)
                t[a[x][j]]=1;
            for(int y=0;y<j;y+=1)
                t[a[i][y]]=1;
            for(int it=0;it<ma;it+=1)
                if(t[it]==0){
                    a[i][j]=it;
                    break;
                }
        }
        int j=l-1;
        for(i=0;i<=l-1;i+=1){
            vector<int> t(ma,0);
            // pos i,j
            for(int x=0;x<i;x+=1)
                t[a[x][j]]=1;
            for(int y=0;y<j;y+=1)
                t[a[i][y]]=1;
            for(int it=0;it<ma;it+=1)
                if(t[it]==0){
                    a[i][j]=it;
                    break;
                }
        }
    }
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n;j+=1)
            cout<<a[i][j]<<' ';
        nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}

//huh i expected some wrong attempts from such a
//tape suported code

//huh i had though of square peri for some reason
// it seems normal iteration is also enough
// oh well atleast it shows i can iterate weirdly
//without help of pen paper
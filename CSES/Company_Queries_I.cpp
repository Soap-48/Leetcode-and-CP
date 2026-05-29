#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n,q;
    cin>>n>>q;
    vector<int> lg(n+1);
    lg[1]=0;
    for(int i=2;i<=n;i+=1)
        lg[i]=lg[i/2]+1;
    vector<vector<int>> st(lg[n]+1,vector<int>(n+1,-1));
    for(int i=2;i<=n;i+=1)  
        cin>>st[0][i];
    for(int i=1;i<=lg[n];i+=1){
        for(int j=1;j<=n;j+=1){
            int k=st[i-1][j];
            st[i][j]=(k==-1)?-1:st[i-1][k];
        }
    }
    int x,k;
    for(int tt=0;tt<q;tt+=1){
        cin>>x>>k;
        int ans=x;
        int i=0;
        while(k>0){
            if(k&1){
                ans=st[i][ans];
            }
            i+=1;
            k=k>>1;
            if(ans==-1)
                break;
        }
        cout<<ans<<'\n';
    }
    return 0;
}

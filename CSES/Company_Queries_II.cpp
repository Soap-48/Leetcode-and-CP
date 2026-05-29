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
    vector<vector<int>> st(lg[n]+1,vector<int>(n+1,1));
    for(int i=2;i<=n;i+=1)  
        cin>>st[0][i];
    for(int i=1;i<=lg[n];i+=1){
        for(int j=1;j<=n;j+=1){
            st[i][j]=st[i-1][st[i-1][j]];
        }
    }
    int a,b;
    for(int tt=0;tt<q;tt+=1){
        cin>>a>>b;
        int l=-1,r=lg[n]+1;
        int ans=1;
        while(r-l>1){
            int m=(l+r)/2;
            if(st[m][a]==st[m][b])
                r=m;
            else 
                l=m;
        }
        
    }
    return 0;
}

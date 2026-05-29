#include <bits/stdc++.h>
using namespace std;

//idea, use memo dp to see all transistion untill we hit base losing state ie 0 to amin-1
// losing is 1, win =0
//if state has atleast one edge to losing state->win (or of all state 1)
//if all edge are to winning state -> lose (or is 0)

int n;

// 0 1 2 3 4
// 1 1 0  
// 4 cals 2=0 and 1=1
//4 is win

//yayay

int help(vector<int> &a,vector<int> &dp,int k){
    if(dp[k]!=-1)
        return dp[k];
    int val=0;
    for(int i=0;i<n&&k>=a[i];i+=1){
        val=(val|help(a,dp,k-a[i]));
    }
   // cerr<<k<<": "<<val<<endl;
    return (dp[k]=1-val);
}

int main() {
	// your code goes here
    int k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> dp(k+1,-1);
    for(int i=0;i<a[0];i+=1)
        dp[i]=1;
   // dp[a[0]]=0;
    int ans=help(a,dp,k);
    if(ans==1)
        cout<<"Second";
    else
        cout<<"First";
}


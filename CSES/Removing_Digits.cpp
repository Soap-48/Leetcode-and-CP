#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int MOD = 1000000007;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll> dp(n+1,1e15);
    dp[n]=0;
    for(int i=n;i>0;i-=1){
        int temp=i;
        while(temp!=0){
            int d=temp%10;
            temp=temp/10;
            if(i>=d)    dp[i-d]=min(dp[i-d],dp[i]+1);
        }
    }
    cout<<dp[0];
    return 0;
}
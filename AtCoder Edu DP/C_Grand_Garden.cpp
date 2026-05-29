// #include <bits/stdc++.h>

// using ll=long long;
// #define vi vector<int>
// #define pb push_back
// #define all(v) (v).begin(),(v).end()
// #define rall(v) (v).rbegin(),(v).rend()
// using namespace std;

// int solve(vector<int> &a,int l, int r){
//     if(l==r){
//         return a[l];
//     }
//     else{
//         int g=0,mi=a[l],ans=0,last=a[l];
//     for(int i=l+1;i<=r;i+=1){
//         if(a[i]<last) {
//             g+=1;
//             ans+=a[i-1];
//         }
//         last=a[i];
//         mi=min(mi,a[i]);
//     }
//     ans+=a[r];
//     mi=min(mi,a[r]);
//     ans-=(g*mi);
//     return ans;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin>>n;
//     vi a(n);
//     int ans=0;
//     for(int i=0;i<n;i+=1)
//         cin>>a[i];
//     int l=-1;
//     for(int i=0;i<n;i+=1){
//         if(a[i]!=0&&l==-1)
//             l=i;
//         else{
//             if(a[i]==0&&l!=-1){
//                 ans+=solve(a,l,i-1);
//                 l=-1;
//             }
//         }
//     }
//     if(a[n-1]!=0)
//         ans+=solve(a,l,n-1);
//     cout<<ans;
//     return 0;
// }
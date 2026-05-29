// #include <bits/stdc++.h>

// using ll=long long;
// #define vi vector<int>
// #define vll vector<ll>
// #define all(v) (v).begin(),(v).end()
// #define rall(v) (v).rbegin(),(v).rend()
// const int MOD = 1000000007;
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     vll fac={1,2,4,6,8,16,24,32,64,120,128,256,512,720,1024,2048,4096,5040,8192,16384,32768,40320,65536,131072,262144,362880,524288,1048576,2097152,3628800,4194304,8388608,16777216,33554432,39916800,67108864,134217728,268435456,479001600,536870912,1073741824,2147483648,4294967296,6227020800,8589934592,17179869184,34359738368,68719476736,87178291200,137438953472,274877906944,549755813888};
//     int t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin>>n;
//         ll ans=0;
//         cerr<<n<<":\n";
//         auto it=fac.end();
//         vi vis(fac.size(),0);
//         while(n>0){
//             it=upper_bound(fac.begin(),it,n);
//             it=prev(it);
//             cerr<<"no: "<<(*it)<<" n:"<<n<<" ans:"<<ans<<"\n";
//             ans+=1;
//             n-=(*it);
//         }
//         cout<<ans<<"\n";
//         cerr<<"\n";
//     }
//     return 0;
// }

/*
what i though earlier- greedy soln where i take the max possible i can take and 
continue untill i get 0, however it can happen that instead of taking the max i 
could take a smaller factorial and end with perfect answer( dont have a case 
but feeling).this wouldnt have happened if it were all 2 powers, hence need
dp, like coin dp but time complexity doesnot allow it,
*/

#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int MOD = 1000000007;

#pragma GCC target("popcnt")

using namespace std;

ll fac[]={1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=LLONG_MAX;
        for(int i=0;i<(1<<14);i+=1){
            int temp=i;ll nn=n;ll val=0;
            for(int j=0;j<14;j+=1){
                if(nn<fac[j]||temp==0)
                    break;
                if(temp&1){
                    nn-=fac[j];
                    val+=1;
                }
                temp=temp/2;
            }
            val+=__builtin_popcountll(nn);
            ans=min(ans,val);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
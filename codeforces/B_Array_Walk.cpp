// #include <bits/stdc++.h>

// #define printarr(x) for(auto no_one_is_gonna_use_this_name:x)\
//  {\
//     cout<<no_one_is_gonna_use_this_name<<' ';\
// }\
// cout<<endl;

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,k,z;
//         cin>>n>>k>>z;
//         if(n>(k+1)) n=k+1;
//         int a[n];
//         int b[n-1];
//         cin>>a[0];
//         int max=0;
//         for(int i=1;i<n;++i)
//         {
//             cin>>a[i];
//             i=i-1;
//             b[i]=a[i]+a[i+1];
//             if(b[i]>max) max=b[i];
//             ++i;
//         }
//        /* for(auto i:a)
//             cout<<i<<' ';
//         for(auto i:b)
//             cout<<i<<' ';
//         */
//        printarr(a);
//        printarr(b);

//     }
//     return 0;
// }

/*
              ...                            
             ;::::;                           
           ;::::; :;                          
         ;:::::'   :;                         
        ;:::::;     ;.                        
       ,:::::'       ;           OOO\         
       ::::::;       ;          OOOOO\        
       ;:::::;       ;         OOOOOOOO       
      ,;::::::;     ;'         / OOOOOOO      
    ;:::::::::`. ,,,;.        /  / DOOOOOO    
  .';:::::::::::::::::;,     /  /     DOOOO   
 ,::::::;::::::;;;;::::;,   /  /        DOOO  
;`::::::`'::::::;;;::::: ,#/  /          DOOO 
:`:::::::`;::::::;;::: ;::#  /            DOOO
::`:::::::`;:::::::: ;::::# /              DOO
`:`:::::::`;:::::: ;::::::#/               DOO
 :::`:::::::`;; ;:::::::::##                OO
 ::::`:::::::`;::::::::;:::#                OO
 `:::::`::::::::::::;'`:;::#                O 
  `:::::`::::::::;' /  / `:#                  
   ::::::`:::::;'  /  /   `#
*/

#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

#define printarr(x) for(auto no_one_is_gonna_use_this_name:x)\
 {\
    cout<<no_one_is_gonna_use_this_name<<' ';\
}\
cout<<endl;

void solve(){
    ll n,k,z;
    cin>>n>>k>>z;
    vll a(n)    ;
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    //state is dp[i][j][p]  i->indice j->no of left moves total z->1 if last left else 0
    queue<array<ll,3>> q;
    vector<vector<vll>> dp(n,vector<vll>(z+1,vll(2,-1e15)));
    q.push({0LL,0LL,0LL});
    dp[0][0][0]=a[0];
    for(int i=0;i<k;i+=1){
        int siz=q.size();
        for(int j=0;j<siz;j+=1){
            auto u=q.front();
            q.pop();
            if(u[0]+1<n){
                ll val=dp[u[0]][u[1]][u[2]]+a[u[0]+1];
                if(val>dp[u[0]+1][u[1]][0]){
                    dp[u[0]+1][u[1]][0]=dp[u[0]][u[1]][u[2]]+a[u[0]+1];
                    q.push({u[0]+1,u[1],0});
                }
            }
            if(u[0]-1>=0&&u[1]+1<=z&&u[2]==0){
                ll val=dp[u[0]][u[1]][u[2]]+a[u[0]-1];
                if(val>dp[u[0]-1][u[1]+1][1]){
                    dp[u[0]-1][u[1]+1][1]=dp[u[0]][u[1]][u[2]]+a[u[0]-1];
                    q.push({u[0]-1,u[1]+1,1});
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<n;i+=1)
        for(int j=0;j<=z;j+=1)
            ans=max({ans,dp[i][j][0],dp[i][j][1]});
    cout<<ans;
    nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
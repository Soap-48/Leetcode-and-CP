// #include <bits/stdc++.h>

// using ll=long long;
// #define vi vector<int>
// #define pb push_back
// #define all(v) (v).begin(),(v).end()
// #define rall(v) (v).rbegin(),(v).rend()
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
//         int n,x;
//         cin>>n>>x;
//         vi a(n+2);
//         a[0]=0;
//         for(int i=1;i<=n;++i)    cin>>a[i];
//         a[n+1]=2*(x-a[n])+a[n]+1;
//         int l=1,r=x,mid;
//         while(l<=r){
//             mid=(l+r)/2;
//             int i;
//             for(i=1;i<=n+1;++i){
//                 if((a[i]-a[i-1])>=mid){
//                     break;
//                 }
//             }
//             if(i==n+1){
//                 r=mid-1;
//             }
//             else{
//                 l=mid+1;
//             }
//         }
//         cout<<mid<<"\n";
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
        int n,x;
        cin>>n>>x;
        vi a(n+1);
        for(int i=0;i<n;++i)    cin>>a[i];
        a[n]=2*x-a[n-1];
        int ans=a[0];
        for(int i=1;i<=n;++i)   ans=max(ans,a[i]-a[i-1]);
        cout<<ans<<"\n";
    }
    return 0;
}
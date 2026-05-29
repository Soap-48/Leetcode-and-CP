// // #include <bits/stdc++.h>

// // using ll=long long;
// // #define vi vector<int>
// // #define pb push_back
// // #define all(v) (v).begin(),(v).end()
// // #define rall(v) (v).rbegin(),(v).rend()
// // using namespace std;

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);
// //     int t;
// //     cin>>t;
// //     while(t--){
// //         ll x,n,m;
// //         cin>>x>>n>>m;
// //         if(x==0){
// //             cout<<"0 0\n";
// //         }
// //         else if(n+m>=27){
// //             int count=0;
// //             while(x>0){
// //                 x=x/2;
// //                 count++;
// //             }
// //             if(m==0||n>count)    cout<<"0 0\n";
// //             else if(m==0) cout<<"1 1\n";
// //             else{
// //                 cout<<"0 1\n";
// //             }
// //         }
// //         else if(n==0){
// //             if(m==0)    cout<<x<<" "<<x<<"\n";
// //             else{
// //                 int ans=x/(1<<m);
// //                 if(x%(1<<m)!=0) ans+=1;
// //                 cout<<ans<<" "<<ans<<"\n";
// //             }
// //         }
// //         else if(m==0){
// //             if(n==0)    cout<<x<<" "<<x<<"\n";
// //             else{
// //                 int ans=x/(1<<n);
// //                 cout<<ans<<" "<<ans<<"\n";
// //             }
// //         }        
// //         else{
// //             int val1=x/(1<<n);
// //             x=val1/(1<<m);
// //             if(val1%(1<<m)!=0)  cout<<x<<" "<<x+1<<"\n";
// //             else cout<<x<<" "<<x<<"\n";
// //         }
// //     }
// //     return 0;
// // }

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
//         int n,x,m;
//         cin>>x>>n>>m;
//         int count=0,temp=x;
//         while(temp>0){
//             count+=1;
//             temp=temp/2;
//         }
//         if(x==0){
//             cout<<"0 0\n";
//             continue;
//         }
//         else if((n+m)>count){
//             if(n>count) cout<<"0 0\n";
//             else cout<<"0 1\n";
//             continue;
//         }
//         else{
//             int val1=x>>(n+m);
//             int val2=x>>n;
//             for(int i=0;i<m&&val2>0;i++){
//                 if(val2%2!=0){
//                     val2+=1;
//                 }
//                 val2=val2/2;
//             }
//             if(n!=0) cout<<val1<<" "<<val2<<"\n";
//             else{
//                 cout<<val2<<" "<<val2<<"\n";
//             }
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

int floor(int x){
    return x/2;
}
int ceil(int x){
    if(x&1){
        return x/2+1;
    }
    else 
    return x/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int x,n,m;
        cin>>x>>n>>m;
        int val=x;
        for(int i=0;i<m;i++){
            val=ceil(val);
            if(val<=1)  break;
        }
        for(int i=0;i<n;i++){
            val=floor(val);
                        if(val<=0)  break;

        }
        cout<<val<<" ";
        val=x;
        for(int i=0;i<n;i++){
            val=floor(val);
                        if(val<=0)  break;

        }
        for(int i=0;i<m;i++){
            val=ceil(val);
                        if(val<=1)  break;

        }
        cout<<val<<"\n";
    }
    return 0;
}
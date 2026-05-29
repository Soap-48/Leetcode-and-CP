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
//         int n;
//         cin>>n;
//         string s;
//         cin>>s;
//         if(n==1){
//             cout<<"-1\n";
//             continue;
//         }
//         // if(s[n-1]=='('&&s[n-2]==')'){
//         //     cout<<"-1\n";
//         //     continue;
//         // }
//         int open=0,close=0;
//         for(auto k:s){
//             if(k=='(')  open++;
//             else close++;
//         }
//         if((close%2)!=(open%2)){
//             cout<<"-1\n";
//             continue;
//         }
//         int ope=0,clos=0;
//         (s[0]=='(')?ope++:clos++;
//         for(int i=1;i<n;i++){
//             if(clos>ope){
//                 if(s[i]==')'&&s[i-1]==')'){
//                     s[i]=s[i-1]='(';
//                     ope+=2;
//                     clos-=2;
//                     i-=1;
//                 }
//             }
//         }
//         open =ope;clos=close;
//         if(open>close){
//             for(int i=n-2;i>0;--i){
//                 if(open==close) break;
//                 else{
//                     if(s[i]=='('&&s[i+1]=='('){
//                         s[i]=s[i-1]=')';
//                         close+=2;
//                         open-=2;
//                     }
//                 }
//             }
//         }
//         if(open==close) cout<<s<<"\n";
//         else cout<<"-1\n";
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

        int n;

void fixstart(vi &a,int x){
    if(x<n){
        // if(a[x]==1){
        //     return;
        // }
        // else{
            ++x;
            if(a[x]==-1){
                a[x]=a[x-1]=1;
            }
            else{
                ++x;
                if(a[x]==1){
                    a[x]=-1;
                    a[x-1]=a[x-2]=1;
                }
                else{
                    fixstart(a,x);
                    if(a[x]==-1) a[x-1]=a[x]=1;
                    else if(a[x]==1)    a[x-1]=a[x]=-1;
                }
            }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vi a(n);
        char c;
        for(int i=0;i<n;++i){
            cin>>c;
            if(c=='(')  a[i]=1;
            else a[i]=-1;
        }
        if(n%2){
            cout<<"-1\n";
        }
        else if(n==2){
            if(a[0]==1&&a[1]==-1)
                cout<<"()\n";
            else
                cout<<"-1\n";
        }
        else{
            if(a[0]!=1){
                fixstart(a,0);
            }
            for(auto k:a)   cout<<k;cout<<endl;;
            // if(a[n-1]!=-1){

            // }
        }
    }
    return 0;
}
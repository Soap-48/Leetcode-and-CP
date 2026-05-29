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
//         vi a(n);
//         for(int i=0;i<n;i++)    cin>>a[i];
//         int groups=0;
//         if(n<=2){
//             cout<<"0\n";
//             continue;
//         }
//         for(int i=1;i<n;i++){
//             if(a[i]>a[i-1]) groups++;
//         }
//         cout<<(((groups-1)>=0)?groups-1:0)<<"\n";
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi a(n);
        for(int i=0;i<n;i++)    cin>>a[i];
        if(n<=2){
            cout<<"0\n";
            continue;
        }
                int ans=0;

        vector<int> s,t;
        s.push_back(1e7);
        t.push_back(1e7);
        for(int i=0;i<n;i++){
            if(a[i]<=s.back()){
                s.push_back(a[i]);
            }
            else if(a[i]<=t.back()){
                t.push_back(a[i]);
            }
            else{
                s.push_back(a[i]);
                ans++;
                swap(s,t);
            }
        }
        
        cout<<ans<<"\n";
    }
    return 0;
}

/*a small y>x
axy a in x or y ie a in x
xay a in y 
xya a in y penalty+1;

*/
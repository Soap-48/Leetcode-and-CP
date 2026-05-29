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
//         int n,k;
//         cin>>n>>k;
//         string s;
//         cin>>s;
//         if(k%2==0){
//             sort(all(s));
//             cout<<s<<"\n";
//         }        
//         else{
//             priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> q;
//             for(int i=0;i<s.size();i+=1){
//                 q.push({s[i],i});
//             }
//             string t;int c=0;
//             while(!q.empty()&&s.size()-c>=3){
//                 auto cc=q.top();
//                 q.pop();
//                 if((((cc.second-c)%2)==0)||(q.size()<=1)){
//                     t+=cc.first;
//                     c+=1;
//                 }
//                 else{
//                     char f=cc.first;
//                     char s;
//                     priority_queue<pair<char,int>> q2;
//                     while(!q.empty()){
//                         auto cc2=q.top();
//                         q.pop();
//                         if((((cc2.second-c)%2)==0)||(q.size()<=1)){
//                             s=cc2.first;
//                             c+=1;
//                             break;
//                         }
//                         q2.push(cc2);
//                     }
//                     while(!q2.empty()){
//                         q.push(q2.top());
//                         q2.pop();
//                     }
//                     t+=s;
//                     t+=f;
//                     c+=1;
//                 }
//             }
//             if(c<=s.size()){
//                 auto a=q.top();
//                 q.pop();
//                 pair<char,int> b;
//                 if(!q.empty()){ b=q.top();
//                 q.pop();
//                 char f,s;
//                 if(a.second>=b.second){
//                     f=b.first;
//                     s=a.first;
//                 }
//                 else{
//                     f=a.first;
//                     s=b.first;
//                 }
//                 t+=f;t+=s;
//                 }
//                 else{
//                     t+=a.first;
//                 }
                
//             }
//             cout<<t<<"\n";
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(k%2==0){
            sort(all(s));
            cout<<s<<"\n";
        }
        else{
            string a[2];
            for(int i=0;i<s.size();i+=1)
                a[i%2]+=s[i];
            sort(all(a[0]));
            sort(all(a[1]));
            for(int i=0;i<s.size();i+=1)
                cout<<a[i%2][(i/2)];
            cout<<"\n";
        }
    }
    return 0;
}
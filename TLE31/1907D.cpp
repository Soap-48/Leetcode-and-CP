// #include <bits/stdc++.h>

// using ll=long long;
// #define vi vector<int>
// #define pb push_back
// #define all(v) (v).begin(),(v).end()
// #define rall(v) (v).rbegin(),(v).rend()
// using namespace std;

// int n;

// bool checkmid(vector<pair<int,int>> &seg,int x){
//     int curr=0;
//     for(int i=0;i<n-1;i++){
//         int a=seg[i].first,b=seg[i].second;
//         if(a>=curr){
//             if(a-curr>x){
//                 return false;
//             }
//             else{
//                 int c=min(b,curr+x);
//                 if((seg[i+1].first)>=a){
//                     curr=c;
//                 }
//                 else{ 
//                     curr=a;
//                 }
//             }
//         }
//         else{
//             if(curr-b>x){
//                 return false;
//             }
//             else{
//                 int c=max(a,curr-x);
//                 if(seg[i+1].second<=a){
//                     curr=c;
//                 }
//                 else{
//                     curr=b;
//                 }
//             }
//         }
//     }
//     int i=n-1,a=seg[i].first,b=seg[i].second;
//     if(a>=curr){
//         if(curr+x<a){
//             return false;
//         }
//         else{
//             if(curr-x>b){
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         vector<pair<int,int>> seg(n);
//         int rmax=-1;
//         for(int i=0;i<n;i++){
//             cin>>seg[i].first;
//             cin>>seg[i].second;
//             rmax=max(rmax,seg[i].second);
//         }
//         int l=seg[0].first,r=rmax,mid;
//         while(l<r){
//             mid=(l-r)/2+r;
//             if(checkmid(seg,mid)){
//                 r=mid-1;
//             }
//             else l=mid+1;
//         }
//         cout<<mid<<"\n";
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

bool check(int k,vector<pair<int,int>> &seg){
    if(k==-1)   return false;
    pair<int,int> pos={0,0};
    for(pair<int,int> i:seg){
        pos.first=max(0,pos.first-k);
        pos.second+=k;
        if((i.first>pos.second&&i.second>pos.second)||(i.first<pos.first&&i.second<pos.first))
            return false;
        else{
            pos.first=max(min(i.first,i.second),pos.first);
            pos.second=min(max(i.first,i.second),pos.second);
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> seg(n);
        int mri=0;
        for(int i=0;i<n;++i){
            cin>>seg[i].first>>seg[i].second;
            mri=max(mri,seg[i].second);
        }
        int l=-1,r=mri;
        for(int b=r;b>=1;b/=2){
            while(!check(l+b,seg)) l+=b;
        }
        cout<<l+1<<"\n";
    }
    return 0;
}
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
        ll n,m;
        cin>>n>>m;
        ll count2=0,count5=0,temp=n;
        // while(temp>10){
        //     temp=temp/10;
        //     c10*=10;
        // }
        while(temp%10==0) temp=temp/10;
        while(temp%5==0){
            temp=temp/5;
            //c5*=5;
            count5++;
        }
        while(temp%2==0){
            temp=temp/2;
            //c2*=2;
            count2++;
        }
        // n2=c5*c2;
        // while(n2%10==0){
        //     n2=n2/10;
        //     count2--;count5--;
        // }
        ll mul=1;
        if(count2>0)
        {
            while(count2>0){
            mul=mul*5;
            count2--;
            }
            while(mul>m)   mul=mul/5;
        }
        else if(count5>0){
            while(count5>0){
            mul=mul*2;
            count5--;
        }
            while(mul>m)   mul=mul/2;
        }
        while(mul*10<m){
            mul=mul*10;
        }
        mul=mul*(m/mul);
        cout<<n*mul<<"\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

long n=0;
long int sum=0;
bool flag=false;
vector<int> set1,set2;

void solve(int i,long s1,long s2){
    if(i==0){
        if(s1==s2){
            flag=true;
            cout<<"YES\n"<<set1.size()<<'\n';
            for(int i:set1) cout<<i<<' ';
            cout<<'\n'<<set2.size()<<'\n';
            for(int i:set2) cout<<i<<' ';
            exit(0);
        }
    }
    if(s1>sum||s2>sum)  return;
    set1.push_back(i);
    solve(i-1,s1+i,s2);
    set1.pop_back();
    set2.push_back(i);
    solve(i-1,s1,s2+i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    sum=n*(n+1)/2;
    if(sum%2==1){
        cout<<"NO";
        return 0;
    }
    sum=sum/2;
    set1.push_back(n);
    solve(n-1,n,0);
    if(flag==false) cout<<"NO";
    return 0;
}
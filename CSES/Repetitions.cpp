#pragma GCC optimize("-O3","unroll-loops")
#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int max=0,curr=0;
    char prev='Z';
    for(char c:s){
        if(c!=prev){
            curr=1;
        }
        else{
            curr++;
        }
                    max=(max>curr)?max:curr;
        prev=c;
    }
    cout<<max;
    return 0;
}
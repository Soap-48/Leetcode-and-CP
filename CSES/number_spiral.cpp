#include <bits/stdc++.h>
using namespace std;

#define even(x) ((x%2)?x-1:x)
#define odd(x) ((x%2)?x:x-1)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        long long int r,c,v;
        cin>>r>>c;
        if(r>=c){
            if(r%2){
                v=(r-1)*(r-1)+c;
            }
            else{
                v=r*r-c+1;
            }
        }
        else{
            if(c%2){
                v=c*c-r+1;
            }
            else{
                v=(c-1)*(c-1)+r;
            }
        }
        cout<<v<<'\n';
    }
    return 0;
}
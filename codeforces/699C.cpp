#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    bool gym=false,code=false;
    int rest=0,in;
    for(int i=0;i<n;i++){
        cin>>in;
        if(in==0){
            rest++;
            gym=code=false;
        }
        else if(in==1){
            if(code){
                rest++;
                code=gym=false;
            }
            else{
                code=true;
                gym=false;
            }
        }
        else if(in==2){
            if(gym){
                rest++;
                gym=code=false;
            }
            else{
                gym=true;
                code=false;
            }
        }
        else{
            if(gym){
                gym=false;
                code=true;
            }
            else if(code){
                code=false;
                gym=true;
            }
        }
    }
            cout<<ans;

    return 0;
}
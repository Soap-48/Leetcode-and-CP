/*
#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        multiset<string> a;
        for(int i=0;i<n;i++){
            cin>>s;
            a.insert(s);
        }
        int count=1;
        while(a.size()>1){
            //
            cout<<"\n\n"<<count<<endl;count++;
                    string ans;
            auto i=--(a.end());
            string k=(*i);
            //
            cout<<k<<" | ";
            a.erase(i);
            reverse(all(k));
            while(k[0]=='0'){
                k.erase(k.begin());
            }
            a.insert(k);
            i=(--a.end());
            auto j= i;--i;
            k=(*i);string l=(*j);
            a.erase(i);a.erase(j);
            if(k>l)   ans=k+l;
            else ans=l+k;
            //
            cout<<k<<" | "<<l<<" | "<<ans;
            a.insert(ans);
        }
        //
        cout<<"\n"<<(*a.begin()).size()<<"|"<<m<<"\n";
        if(((*a.begin()).size())<=m)  cout<<"Anna\n";
        else cout<<"Sasha\n";
    }
    return 0;
}

*/



#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        ll siz=0;
        vector<ll> zero;
        for(int i=0;i<n;i++){
            cin>>s;
            siz+=s.size();
            if(s.back()=='0'){
                ll j=0;
                for(auto k=(--s.end());(*k)=='0';--k,++j)   ;
                zero.push_back(j);
            }
        }
        sort(zero.rbegin(),zero.rend());
        for(ll i=0;i<zero.size();i+=2){
            siz-=zero[i];
        }
        if(siz<=m)  cout<<"Anna\n";
        else cout<<"Sasha\n";
    }
    return 0;
}
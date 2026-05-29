/*
              ...
             ;::::;
           ;::::; :;
         ;:::::'   :;
        ;:::::;     ;.
       ,:::::'       ;           OOO\
       ::::::;       ;          OOOOO\
       ;:::::;       ;         OOOOOOOO
      ,;::::::;     ;'         / OOOOOOO
    ;:::::::::`. ,,,;.        /  / DOOOOOO
  .';:::::::::::::::::;,     /  /     DOOOO
 ,::::::;::::::;;;;::::;,   /  /        DOOO
;`::::::`'::::::;;;::::: ,#/  /          DOOO
:`:::::::`;::::::;;::: ;::#  /            DOOO
::`:::::::`;:::::::: ;::::# /              DOO
`:`:::::::`;:::::: ;::::::#/               DOO
 :::`:::::::`;; ;:::::::::##                OO
 ::::`:::::::`;::::::::;:::#                OO
 `:::::`::::::::::::;'`:;::#                O
  `:::::`::::::::;' /  / `:#
   ::::::`:::::;'  /  /   `#
*/

#include <bits/stdc++.h>

using ll = long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define nl cout << '\n'
const int MOD = 1000000007;
using namespace std;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> f(26, 0);
    for (int i = 0; i < n; i += 1)
        f[s[i] - 'a'] += 1;
    ll cans = 1e9;
    string sss;
    for (int i = 1; i <= 26; i += 1) {
        if (n % i == 0) {
            vector<int> f2=f;
            string s2=s;
            ll c = n / i; // req freq, i is no of characters
            ll ans = 0;
            vector<pair<int, char>> tt;
            for (int j = 0; j < 26; j += 1)
                if (f2[j] < c)
                    tt.push_back({f2[j], j + 'a'});
            sort(rall(tt));
            int hitler = i +tt.size() - 26;
           // cerr<<i<<'|'<<tt.size()<<'|'<<hitler<<endl;
            set<char> laggaye;
            for (int j = hitler; j < tt.size(); j += 1)
                laggaye.insert(tt[j].second);
            for (int j = 0; j < n; j += 1) {
                if (f2[s2[j] - 'a'] > c) {
                   // cerr<<"1. "<<j<<' '<<s2[j]<<' '<<f2[s2[j]-'a']<<endl;
                    f2[s2[j] - 'a'] -= 1;
                    s2[j] = '.';
                    ans += 1;
                } else if (f2[s2[j] - 'a'] < c && laggaye.find(s2[j]) != laggaye.end()) {
                    s2[j] = '.';
                    ans += 1;
                }
            }
          //  cerr<<s2<<endl;
            if(cans<=ans)   continue;
            int it = 0;
            for (int j = 0; j < n; j += 1) {
                if (s2[j] == '.') {
                    s2[j] = tt[it].second;
                    tt[it].first += 1;
                    if (tt[it].first >= c)
                        it += 1;
                }
            }
            cans=ans;
            sss=s2;
        }
    }
    cout<<cans;nl;cout<<sss;nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
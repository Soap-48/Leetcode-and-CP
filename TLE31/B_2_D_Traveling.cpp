// #include <bits/stdc++.h>

// using ll=long long;
// #define vi vector<int>
// #define vll vector<ll>
// #define all(v) (v).begin(),(v).end()
// #define rall(v) (v).rbegin(),(v).rend()
// #define nl cout<<'\n'
// const int MOD = 1000000007;
// using namespace std;

// void solve(){
//     int n,k,a,b;
//     cin>>n>>k>>a>>b;
//     vector<vll> city(n+1,vll(2,0));
//     for(int i=1;i<=n;i+=1)
//         cin>>city[i][0]>>city[i][1];
//     if(a<=k&&b<=k)  {cout<<0;nl;return;}
//     ll ans=abs(city[a][0]-city[b][0])+abs(city[a][1]-city[b][1]);
//     if(k<=1){
//         cout<<ans;nl;return;
//     }
//     ll ca=1e10;
//     if(a>k) for(int i=1;i<=k;i+=1){
//         ca=min(ca,abs(city[a][0]-city[i][0])+abs(city[a][1]-city[i][1]));
//     }
//     else ca=0;
//     ll cb=1e10;
//     if(b>k) for(int i=1;i<=k;i+=1){
//         cb=min(cb,abs(city[b][0]-city[i][0])+abs(city[b][1]-city[i][1]));
//     }
//     else cb=0;
//     cout<<min(ans,ca+cb);
//     nl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
#define all(s) s.begin(), s.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int _N = 1e5 + 5;

int T;

void solve() {
	int n, k, s, t; cin >> n >> k >> s >> t;
	vector<int> x(n + 1), y(n + 1);
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	ll ans = llabs(x[s] - x[t]) + llabs(y[s] - y[t]);
	ll mins = LLONG_MAX / 2, mint = LLONG_MAX / 2;
	for (int i = 1; i <= k; i++) {
		mins = min(mins, llabs(x[s] - x[i]) + llabs(y[s] - y[i]));
		mint = min(mint, llabs(x[t] - x[i]) + llabs(y[t] - y[i]));
	}
	ans = min(ans, mins + mint);
	cout << ans << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		solve();
	}
}
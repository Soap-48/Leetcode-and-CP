/*#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

void printInt128(__int128 x) {
    if (x == 0) { cout << 0; return; }
    string s;
    bool neg = x < 0;
    if (neg) x = -x;
    while (x > 0) {
        s.push_back('0' + (x % 10));
        x /= 10;
    }
    if (neg) cout << '-';
    reverse(s.begin(), s.end());
    cout << s;
}

bool power_leq(__int128 base, int n, __int128 limit) {
    if (base == 0) return 0 <= limit; 
    __int128 result = 1;
    for (int i = 0; i < n; i++) {
        if (result > limit / base) return false;
        result *= base;
    }
    return result <= limit;
}


// Check if nth root exists
bool isPerfectNthRoot(__int128 x, int n) {
    if (x < 0 && n % 2 == 0) return false; // even root of negative
    __int128 lo = 0, hi = x, ans = -1;

    while (lo <= hi) {
        __int128 mid = (lo + hi) / 2;

        if (power_leq(mid, n, x)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    // verify exact
    __int128 val = 1;
    for (int i = 0; i < n; i++) val *= ans;
    return val == x;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p;
    cin>>p;
    while(p--){
        int n;
        cin>>n;
        __int128 t=1;
        int in;
        if(n==1){
            cin>>in;
            cout<<"YES\n";
            continue;
        }
        for(int i=0;i<n;i++){
            cin>>in;
            t=t*in;
        }
            if(isPerfectNthRoot(t,n)){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        

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


vector<int> primes;

// Sieve to generate primes up to 1000
void sieve(int n=1e6+1) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) 
        if (isPrime[i]) primes.push_back(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    sieve();
    while(t--){
        map<int,ll> m;
        int n,in;
        cin>>n;
        if(n==1){
            cin>>in;
            cout<<"YES\n";
            continue;
        }
        for(int i=0;i<n;i++){
            cin>>in;
           // int dummmmmm=in;
           if(find(all(primes),in)!=primes.end()){
                m[in]++;
           }
           else{
            for(auto p:primes){
                if(in<p)    break;
                while(in%p==0) {
                    m[p]++;
                    in=in/p;
                }
            }
        }
        }
        bool flag=true;
        for(auto a:m){
            if((a.second%n)!=0){
                cout<<"NO\n";
                flag=false;
                break;
            }
        }
        if(flag)    cout<<"YES\n";
    }
    return 0;
}
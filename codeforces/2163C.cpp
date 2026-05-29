#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<long long>
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
        ll n;
        cin>>n;
        vector<vll> a(2,vll(n));
        for(int i=0;i<2;i+=1)
            for(int j=0;j<n;j+=1)
                cin>>a[i][j];
        vector<pair<ll,ll>> ans;
        vector<vll> pmax(2,vll(n)),pmin(2,vll(n));
        pmax[0][0]=pmin[0][0]=a[0][0];
        pmax[1][n-1]=pmin[1][n-1]=a[1][n-1];
        for(int i=1;i<n;i+=1){
            pmax[0][i]=max(pmax[0][i-1],a[0][i]);
            pmin[0][i]=min(pmin[0][i-1],a[0][i]);
        }
        for(int i=n-2;i>=0;i-=1){
            pmax[1][i]=max(pmax[1][i+1],a[1][i]);
            pmin[1][i]=min(pmin[1][i+1],a[1][i]);
        }
        for(int down=0;down<n;down+=1){
            ans.push_back(pair(min(pmin[0][down],pmin[1][down]),max(pmax[0][down],pmax[1][down])));
        }
        ans.push_back(pair(0,0));
        sort(all(ans));
        ll cmax=ans.back().second;
        for(int i=ans.size()-1;i>=0;i-=1){
            cmax=min(cmax,ans[i].second);
            ans[i].second=cmax;
        }
        long long aans=0;
        for(int i=1;i<ans.size();i+=1){
            aans+=(ans[i].first-ans[i-1].first)*(2*n-ans[i].second+1);
        }
        cout<<aans<<"\n";
    }
    return 0;
}

/*********
 Author : Aman Gupta  (^_^)
**********/

// #include <bits/stdc++.h>
// #define int long long
// #define all(x) x.begin(), x.end()
// #define rall(x) x.rbegin(), x.rend()
// #define endl "\n"
// #define pb push_back
// #define vi vector<int>
// #define INT_MIN LLONG_MIN
// #define INT_MAX LLONG_MAX
// using namespace std;
// int loga(int x);
// int lcm(int a, int b);
// bool isPrime(int n);
// int second_max_index(vector<int> &a);
// int kadane(vector<int> a, int s, int e);
// vi bit(int x);

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int n;
//         cin >> n;
//         vi a(n+1LL), b(n+1LL);
//         for(int i = 1; i <= n; i++)
//             cin >> a[i];
//         for(int i = 1; i <= n; i++)
//             cin >> b[i];


//         vi Ma(n+1), ma(n+1), Mb(n+1), mb(n+1);
//         ma[1] = a[1], Ma[1] = a[1];
//         for(int i = 2; i <= n; i++)
//         {
//             ma[i] = min(ma[i-1], a[i]);
//             Ma[i] = max(ma[i-1], a[i]);
//         }
//         mb[n] = b[n], Mb[n] = b[n];
//         for(int i = n-1; i >= 1; i--)
//         {
//             mb[i] = min(mb[i+1], b[i]);
//             Mb[i] = max(Mb[i+1], b[i]);
//         }

//         vector<pair<int, int>> ans;
        
//         for(int i = 1; i <= n; i++)
//         {
//             ans.pb({min(ma[i], mb[i]), max(Ma[i], Mb[i])});
//         }

//         ans.pb({0, 0});

//         sort(all(ans));  
//         int cmax = ans.back().second;      

//         for(int i = ans.size()-1; i >= 0; i--)
//         {
//             cmax = min(cmax, ans[i].second);
//             //ans[i].second = min(ans[i+1].second, ans[i].second);
//             ans[i].second = cmax;
//         }

//         int fans = 0;
//         for(int i = 1; i < ans.size(); i++)
//         {
//             fans += (ans[i].first-ans[i-1].first)*(2*n-ans[i].second+1);
//         }
//         cout << fans << endl;   
        
//     }

//     return 0;
// }



// int loga(int x)
// {
//     return (63 - __builtin_clzll(x)); // this "ajeeb sa function" returns the number of leading zeroes
// }

// int lcm(int a, int b)
// {
//     return (a / __gcd(a, b)) * b;
// }

// bool isPrime(int n)
// {
//     if (n <= 1)
//         return false;
//     for (int i = 2; i * i <= n; i++)
//         if (n % i == 0)
//             return false;
//     return true;
// }

// int second_max_index(vector<int> &a)
// {
//     int index = max_element(all(a)) - a.begin();
//     int ans = INT_MIN, ans_index = -1;
//     for (int i = 0; i < (int)a.size(); i++)
//         if (i != index && a[i] > ans)
//             ans = a[i], ans_index = i;
//     return ans_index;
// }

// int kadane(vector<int> a, int s, int e)
// {
//     if (s > e)
//         return -1;
//     int max_ending = 0, ans = a[s];
//     for (int i = 1; i <= e - s + 1; i++)
//     {
//         int curr = max_ending + a[s - 1 + i];
//         max_ending = max(curr, a[s - 1 + i]);
//         ans = max(ans, max_ending);
//     }
//     return ans;
// }

// vi bit(int x)
// {
//     vi b(32);
//     int i = 0;
//     while(x)
//     {
//         b[i++] += (x&1);
//         x = x>>1;
//     }
//     return b;
// }
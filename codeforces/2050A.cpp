#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
    int n,m;
    cin>>n>>m;
    string data[n];
    for(int i=0;i<n;++i)
    {
        cin>>data[i];
    }
    int i=0;
    while(m>=0)
    {
        m=m-data[i].size();
        ++i;
    }
    cout<<i-1<<'\n';
}
    return 0;
}
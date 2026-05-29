#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

int sqr(int x){
    for(int i=1;i<x;i+=1)
        if(i*i==x)  return i;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    map<int, set<int>> a = {
        {4 * 8,   {4, 8}},
        {4 * 15,  {4, 15}},
        {4 * 16,  {4, 16}},
        {4 * 23,  {4, 23}},
        {4 * 42,  {4, 42}},
        {8 * 15,  {8, 15}},
        {8 * 16,  {8, 16}},
        {8 * 23,  {8, 23}},
        {8 * 42,  {8, 42}},
        {15 * 16, {15, 16}},
        {15 * 23, {15, 23}},
        {15 * 42, {15, 42}},
        {16 * 23, {16, 23}},
        {16 * 42, {16, 42}},
        {23 * 42, {23, 42}}
    };
    int n1,n2,n3;
    vi ans(6,0);
    cout<<"? 1 2"<<endl;
    cin>>n1;
    cout<<"? 2 3"<<endl;
    cin>>n2;
    cout<<"? 3 4"<<endl;
    cin>>n3;
    set<int> s1,s2,s3;
    s1=a[n1];
    s2=a[n2];
    s3=a[n3];
    set_intersection(all(s1),all(s2),&ans[1]);
    set_intersection(all(s3),all(s2),&ans[2]);
    int sum1=0,sum2=0;
    for(int i:s1)   sum1+=i;
    for(int i:s3)   sum2+=i;
    ans[0]=sum1-ans[1];
    ans[3]=sum2-ans[2];
    int sq;
    cout<<"? 5 5"<<endl;
    cin>>sq;
    ans[4]=sqr(sq);
    int sum=0;
    for(int i=0;i<5;i+=1)   sum+=ans[i];
    ans[5]=108-sum;
    cout<<"! ";
    for(int i:ans)  cout<<i<<" ";
    cout<<endl;
    return 0;
}
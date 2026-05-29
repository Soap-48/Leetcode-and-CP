const long long MOD=1000000007;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
        b =b/2;
    }
    return res;
}

bool comp(pair<int,int> a,pair<int,int> b){
    if(b.second==0)
        return false;
    if(a.second==0||a.first>b.first)
        return true;
    if(b.first>a.first)
        return false;
    return (a.second<b.second);

}

class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        long long pow=0;
        long long ans=0;
        int n=nums1.size();
        for(int i=0;i<n;i+=1){
            pow+=nums1[i];
            pow+=nums0[i];
        }
        vector<pair<int,int>> val(n);
        for(int i=0;i<n;i+=1){
            val[i].first=nums1[i];
            val[i].second=nums0[i];
        }
        sort(val.begin(),val.end(),comp);
        pow-=1;
        for(int i=0;i<n;i+=1){
            ans=(ans+binpow(2ll,pow+1))%MOD;
            pow-=val[i].first;
            ans=((ans-binpow(2ll,pow+1))%MOD+MOD)%MOD;
            pow-=val[i].second;
        }
        return ans;
    }
};
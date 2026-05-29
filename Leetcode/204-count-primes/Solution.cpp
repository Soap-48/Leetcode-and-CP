class Solution {
public:
    int countPrimes(int n) {
        vector<long long> sieve(n,1);
        for(long long i=2;i<n;i+=1){
           if(sieve[i]) for(long long j=i*i;j<n;j+=i){
                sieve[j]=0;
            }
        }
        int ans=0;
        for(int i=2;i<n;i+=1)
            ans+=sieve[i];
        return ans;
    }
};
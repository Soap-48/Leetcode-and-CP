class Solution {
public:

    bool check(vector<int> & a, int m, int k){
        int boq=0,adj=0;
        for(auto i:a){
            if(i==1)
                adj+=1;
            else{
                boq+=(adj/k);
                adj=0;
            }
        }
        boq+=(adj/k);
        if(boq>=m)
            return true;
        else
            return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int l=*(min_element(bloomDay.begin(),bloomDay.end())),r=*(max_element(bloomDay.begin(),bloomDay.end()));
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
                    vector<int> bloom(n);
            for(int i=0;i<n;i+=1)
                if(mid>=bloomDay[i])
                    bloom[i]=1;
            bool flag=check(bloom,m,k);
            if(flag){
                r=mid-1;
                ans=mid;
            }
            else
                l=mid+1;
            }
        
        return ans;
    }
};
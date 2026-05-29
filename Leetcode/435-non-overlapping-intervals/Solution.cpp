class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            if(a[1]!=b[1])
                return a[1]<b[1];
            else
                return a[0]>b[0];
        });
        int end=-1e6,ans=0;
        for(int i=0;i<n;i+=1){
            if(intervals[i][0]>=end){
                ans+=1;
                end=intervals[i][1];
            }
        }
        return n-ans;
    }
};
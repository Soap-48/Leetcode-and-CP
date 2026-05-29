class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int max=arr.back()-arr.size();
        if(k>max)
            return arr.size()+k;
        else{
            int l=0,r=arr.size()-1;
            int a=-1;
            while(l<=r){
                int m=(l+r)/2;
                int mis=arr[m]-m-1;
                if(mis>=k)
                    r=m-1;
                else{
                    l=m+1;
                    a=m;
                }
            }
            if(a==-1)
                return k;
            else
                return k+a+1;
        }
    }
};
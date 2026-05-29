class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n=nums1.size(),m=nums2.size(),s=(n+m+1)/2;
            int l=0,r=n;
            while(l<=r){
                int mid=(l+r)/2;
                int n2=s-mid;
                if(n2>m){
                    l=mid+1;
                    continue;
                }
                else if(mid>s){
                    r=mid-1;
                    continue;
                }
                int vl1,vl2,vr1,vr2;
                vl1=((mid>0)?nums1.at(mid-1):INT_MIN);
                vl2=((n2>0)?nums2.at(n2-1):INT_MIN);
                vr1=((mid<n)?nums1.at(mid):INT_MAX);
                vr2=((n2<m)?nums2.at(n2):INT_MAX);
                if(vl1>vr2){
                    r=mid-1;
                }
                else if(vl2>vr1){
                    l=mid+1;
                }
                else{
                    if((n+m)&1){
                        return max(vl1,vl2);
                    }
                    else{
                        return (max(vl1,vl2)+min(vr1,vr2))/2.0;
                    }
                }
            }
                    return -1;

        }
};
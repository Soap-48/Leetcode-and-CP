class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> a(256,0);
        if(s==""){
            return 0;
        }
        int ans=0,l=0;
        for(int i=0;i<s.size();i+=1){
            a[(int)s[i]-1]+=1;
            if(a[(int)s[i]-1]>1){
                while(a[(int)s[i]-1]>1){
                    a[(int)s[l++]-1]-=1;
                }
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
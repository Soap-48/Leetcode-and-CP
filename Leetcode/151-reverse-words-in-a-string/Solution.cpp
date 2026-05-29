class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0,n=s.length();
        while(i<n){
            if(s[i]==' '){
                i+=1;
            }
            else{
                int start=i;
                while(i<n&&s[i]!=' ')
                    i+=1;
                if(!ans.empty())
                    ans+=" ";
                for(int j=i-1;j>=start;j-=1)
                    ans+=s[j];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
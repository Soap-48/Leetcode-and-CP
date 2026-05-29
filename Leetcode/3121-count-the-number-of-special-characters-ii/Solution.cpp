const int inf=1e8;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> m(52,inf);
        for(int i=0;i<word.size();i+=1){
            if(word[i]<='Z'){
                if(m[word[i]-'A'+26]==inf)
                    m[word[i]-'A'+26]=i;
            }
            else{
                m[word[i]-'a']=i;
            }
        }
        int ans=0;
        for(int i=0;i<26;i+=1){
            if(m[i+26]!=inf&&m[i]<m[i+26])
                ans+=1;
        }
        return ans;
    }
};
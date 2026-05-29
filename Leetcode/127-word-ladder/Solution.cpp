class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto chk=[](string a,string b){
            int diff=0;
            for(int i=0;i<a.length();i+=1)
                diff+=(a[i]!=b[i]);
            return diff==1;
        };
        int d=1;
        vector<bool> vis(wordList.size(),false);
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int siz=q.size();
            for(int it=0;it<siz;it+=1){
                string &i=q.front();
                if(i==endWord)
                    return d;
                for(int j=0;j<wordList.size();j+=1)
                    if(vis[j]==false&&chk(i,wordList[j])){
                        vis[j]=true;
                        q.push(wordList[j]);
                    }
                q.pop();
            }
            d+=1;
        }
        return 0;
    }
};
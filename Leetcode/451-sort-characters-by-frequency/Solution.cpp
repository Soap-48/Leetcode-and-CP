class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> m;
        string ans;
        for(char c='a';c<='z';c+=1)
            m.push_back(pair(0,c));
        for(char c='A';c<='Z';c+=1)
            m.push_back(pair(0,c));
        for(char i='0';i<='9';i+=1)
            m.push_back(pair(0,i));
        for(char c:s){
            if(c>='A'&&c<='Z'){
                m[(c-'A')+26].first+=1;
            }
            else if(c>='a'&&c<='z'){
                m[(c-'a')].first+=1;
            }
            else if(c>='0'&&c<='9'){
                m[(c-'0')+52].first+=1;
            }
        }
        sort(m.rbegin(),m.rend());
        for(int i=0;i<62;i+=1){
            for(int j=0;j<m[i].first;j+=1)
                ans+=m[i].second;
        }
        return ans;
    }
};
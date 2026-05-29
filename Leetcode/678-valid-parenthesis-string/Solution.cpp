class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        set<int> sc;
        sc.insert(0);
        for(int i=0;i<n;i+=1){
            set<int> st;
            if(s[i]=='('){
                for(const int &i:sc)
                    st.insert(i+1);
            }
            else if(s[i]==')'){
                for(const int &i:sc)
                    if(i>0) st.insert(i-1);
            }
            else{
                for(const int &i:sc){
                    st.insert(i+1);
                    st.insert(i);
                    if(i>0) st.insert(i-1);
                }
            }
            sc=st;
        }
        return sc.count(0)?true:false;

    }
};
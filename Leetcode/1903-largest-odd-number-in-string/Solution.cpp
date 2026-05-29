class Solution {
public:
    string largestOddNumber(string num) {
        string ans="",val="";
        for(auto i:num){
            val+=i;
            if(i!='0'&&i!='2'&&i!='4'&&i!='6'&&i!='8')  ans=val;
        }
        return ans;
    }
};
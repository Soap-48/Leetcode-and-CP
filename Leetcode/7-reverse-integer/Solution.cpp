class Solution {
public:
    int reverse(long int x) {
            vector<short unsigned int> dig;
    unsigned long int n;
    int flag;
    if(x>=0)
        {
            flag=1;
            n=x;
        }
    else
    {
        flag=-1;
        n=-x;
    }
    while(n>=1)
    {
        dig.push_back(n%10);
        n=n/10;
    }
    n=0;
    for(short unsigned k:dig)
    {
        n=n*10+k;
    }
    if(n>=(1UL<<31))  return 0;
    return n*flag;     
    }
};
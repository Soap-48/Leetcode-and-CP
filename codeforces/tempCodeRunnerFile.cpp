void solve(){
    ll x;
    cin>>x;
    ll in;
    cout<<"? 10000000000000000 10000000000000000"<<endl;
    in=gcd(x+10000000000000000ll,10000000000000000);
    if(in==10000000000000000ll){
        cout<<"! 0"<<endl;
        return;
    }
    else{
        ll curr=1;
        ll a=1,b=2;
        ll la=a,lb=b;
        ll w=0;
        for(int i=1;i<=55;i+=1){
            curr*=2ll;
            la=a;lb=b;
            if(curr>=10000000000000000ll){
                break;
            }
            cout<<"? "<<a<<" "<<curr<<endl;
            in=gcd(x+a,curr);
            if(in==-1){
                return;
            }
            //cerr<<"LOG: "<<curr<<"*n-";
            if(in==curr){
                w=1;
               // cerr<<a<<endl;
                b=a+curr;
            }
            else{
               // cerr<<b<<endl;
                a=b;
                b+=curr;
                w=2;
            }
            //cerr<<"curr:"<<curr;
            //cerr<<" a:"<<la<<" b:"<<lb<<endl;;
        }
        if(w==1) cout<<"! "<<(curr-la)<<endl;
        else    cout<<"! "<<(curr-lb)<<endl;
    }
}
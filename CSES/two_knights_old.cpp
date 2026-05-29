#include <bits/stdc++.h>
using namespace std;

long long int ans;
short int board[10000][10000]={};

void foo(int n,int x,int y,int placed){
    if(placed==2){
        ans++;
        return;
    }
    for(int row=x;row<n;row++){
    for(int i=(row==x)?y:0;i<n;i++)   {
            bool flag[8]={};
        if(board[row][i]==0){
            board[row][i]=1;
            /*if(row-1>=0&&i+2<n) {board[row-1][i+2]=1;flag[0]=true;}
            if(row-1>=0&&i-2>=0) {board[row-1][i-2]=1;flag[1]=true;}
            if(row+1<n&&i+2<n) {board[row+1][i+2]=1;flag[2]=true;}
            if(row+1<n&&i-2>=0) {board[row+1][i-2]=1;flag[3]=true;}
            if(row-2>=0&&i+1<n) {board[row-2][i+1]=1;flag[4]=true;}
            if(row-2>=0&&i-1>=0) {board[row-2][i-1]=1;flag[5]=true;}
            if(row+2<n&&i+1<n) {board[row+2][i+1]=1;flag[6]=true;}
            if(row+2<n&&i-1>=0) {board[row+2][i-1]=1;flag[7]=true;}
            */

            if(row - 1 >= 0 && i + 2 < n && board[row - 1][i + 2] == 0) {
    board[row - 1][i + 2] = 1;
    flag[0] = true;
}

if(row - 1 >= 0 && i - 2 >= 0 && board[row - 1][i - 2] == 0) {
    board[row - 1][i - 2] = 1;
    flag[1] = true;
}

if(row + 1 < n && i + 2 < n && board[row + 1][i + 2] == 0) {
    board[row + 1][i + 2] = 1;
    flag[2] = true;
}

if(row + 1 < n && i - 2 >= 0 && board[row + 1][i - 2] == 0) {
    board[row + 1][i - 2] = 1;
    flag[3] = true;
}

if(row - 2 >= 0 && i + 1 < n && board[row - 2][i + 1] == 0) {
    board[row - 2][i + 1] = 1;
    flag[4] = true;
}

if(row - 2 >= 0 && i - 1 >= 0 && board[row - 2][i - 1] == 0) {
    board[row - 2][i - 1] = 1;
    flag[5] = true;
}

if(row + 2 < n && i + 1 < n && board[row + 2][i + 1] == 0) {
    board[row + 2][i + 1] = 1;
    flag[6] = true;
}

if(row + 2 < n && i - 1 >= 0 && board[row + 2][i - 1] == 0) {
    board[row + 2][i - 1] = 1;
    flag[7] = true;
}


            foo(n,row,i,placed+1);
            board[row][i]=0;

            /*if(board[row-1][i+2]==1)    board[row-1][i+2]=0;
            if(board[row-1][i-2]==1)    board[row-1][i-2]=0;
            if(board[row+1][i+2]==1)    board[row+1][i+2]=0;
            if(board[row+1][i-2]==1)    board[row+1][i-2]=0;
            if(board[row-2][i+1]==1)    board[row-2][i+1]=0;
            if(board[row-2][i-1]==1)    board[row-2][i-1]=0;
            if(board[row+2][i+1]==1)    board[row+2][i+1]=0;
            if(board[row+2][i-1]==1)    board[row+2][i-1]=0;*/

            if(flag[0]==true) board[row-1][i+2]=0;
            if(flag[1]==true) board[row-1][i-2]=0;
            if(flag[2]==true) board[row+1][i+2]=0;
            if(flag[3]==true) board[row+1][i-2]=0;
            if(flag[4]==true) board[row-2][i+1]=0;
            if(flag[5]==true) board[row-2][i-1]=0;
            if(flag[6]==true) board[row+2][i+1]=0;
            if(flag[7]==true) board[row+2][i-1]=0;
        }
    }
}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    cout<<"0\n";
    for(int k=2;k<=t;k++){
        ans=0;
        foo(k,0,0,0);
        cout<<ans<<'\n';
    }
    return 0;
}
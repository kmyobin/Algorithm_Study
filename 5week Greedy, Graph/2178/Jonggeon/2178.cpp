//1시간 이내
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int n;
int m;
int board[101][101];
int dp[101][101];
//4가지 방향
int dirRow[4] = {1,0,-1,0};
int dirCol[4] = {0,1,0,-1};
//범위 체크
bool check(int row,int col){
   if(row<1||row>n||col<1||col>m)return false;
   else return true;
}
//dfs로 갈수있는 곳 파악, 이미 지나간곳중 현재이동보다 크기가 적으면 멈춘다
void dfs(int row,int col){
   for(int i=0;i<4;i++){
       int x = row+dirRow[i];
       int y = col+dirCol[i];
       if(check(x,y)&& board[x][y] == 1 &&dp[x][y] > dp[row][col]+1){
           dp[x][y]=dp[row][col]+1;
           dfs(x,y);
       }
   }
}
int main(void) {
   cin >> n>>m;
   for(int i=1;i<=n;i++){
       string temp = "";
       cin>>temp;
       for(int j=1;j<=temp.length();j++){
           board[i][j]=temp[j-1]-'0';
           dp[i][j]=9999999;
       }

   }

   dp[1][1] = 0;
   dfs(1,1);
   cout<<dp[n][m]+1;
   return 0;
}


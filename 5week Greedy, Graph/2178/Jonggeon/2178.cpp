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


//파이프 옮기기 30분이내
//dfs를 활용해 풀었지만 파이프의 방향으로 토대로 dp로도 풀 수 있다.
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int n;
int board[17][17];
int answer=0;
bool checkMap(int row,int col){
   if(row>n || col>n)return false;
   else return true;
}
//direction 0=가로 1=대각 2=세로
//(n,m) 파이프 끝 위치
void dfs(int direction,int row,int col){
   //도착
   if(row==n && col ==n){
       answer++;
   }

   else {
       switch(direction){
           case 0:
               //가로이동
               if(checkMap(row,col+1)&&board[row][col+1]==0){
                   dfs(0,row,col+1);
               }
               //대각이동
               if(checkMap(row+1,col+1)&&board[row][col+1]==0&&board[row+1][col]==0&&board[row+1][col+1]==0){
                   dfs(1,row+1,col+1);
               }
               break;
           case 1:
               //가로이동
               if(checkMap(row,col+1)&&board[row][col+1]==0){
                   dfs(0,row,col+1);
               }
               //대각이동
               if(checkMap(row+1,col+1)&&board[row][col+1]==0&&board[row+1][col]==0&&board[row+1][col+1]==0){
                   dfs(1,row+1,col+1);
               }
               //세로이동
               if(checkMap(row+1,col)&&board[row+1][col]==0){
                   dfs(2,row+1,col);
               }
               break;
           default:
               //대각이동
               if(checkMap(row+1,col+1)&&board[row][col+1]==0&&board[row+1][col]==0&&board[row+1][col+1]==0){
                   dfs(1,row+1,col+1);
               }
               //세로이동
               if(checkMap(row+1,col)&&board[row+1][col]==0){
                   dfs(2,row+1,col);
               }
               break;

       }

   }
}

int main(void) {

   cin >> n;
   for(int i=1;i<=n;i++){
       for(int j=1; j<=n; j++){
           int temp;
           cin>>temp;
           board[i][j]=temp;
       }
   }
   dfs(0,1,2);
   cout<<answer;
   return 0;
}


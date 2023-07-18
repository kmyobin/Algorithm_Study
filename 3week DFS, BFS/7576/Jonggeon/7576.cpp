#include <iostream>
#include <queue>

using namespace std;
int board[1001][1001];
int m,n;
int answer = -1;
//날짜와 위치를 저장하는 큐
queue<pair<int,pair<int,int>>> q;

//익지 않은 감자의 개수를 파라미터로 받는다
void dp(int zeroCnt){
   while(!q.empty()){
        // 현재의 날짜와 위치를 받는다.
       int count = q.front().first;
       int i = q.front().second.first;
       int j = q.front().second.second;
       q.pop();
       board[i][j] = 1;
       answer = count;
       // 자신의 주변에 익지 않은 감자가 있다면 다음날 감자가 익어야 한다
       // q에 다음날과 위치를 저장한다.
       if( i - 1 >=0 && board[i-1][j] == 0){
           zeroCnt --;
           board[i-1][j] = 2;
           q.push(make_pair(count+1,make_pair(i-1,j)));
       }
       if(j - 1 >= 0 && board[i][j-1] == 0 ){
           zeroCnt --;
           board[i][j-1] = 2;
           q.push(make_pair(count+1,make_pair(i,j-1)));
       }
       if(i+1 < n && board[i+1][j] == 0){
           zeroCnt --;
           board[i+1][j] = 2;
           q.push(make_pair(count+1,make_pair(i+1,j)));
       }
       if(j+1 < m && board[i][j+1] == 0){
           zeroCnt --;
           board[i][j+1] = 2;
           q.push(make_pair(count+1,make_pair(i,j+1)));
       }
   }
        //반복문을 전부 실행했음에도 아직 익지 않은 감자가 있다면 -1출력
       if(zeroCnt != 0) answer =-1;
}

int main(void) {
   cin >>m>>n;
   int zeroCnt = 0;
   //감자의 위치를 받고 감자가 익지 않은 곳의 개수를 측정한다.
   for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
           int num;
           cin>> num;
           board[i][j] = num;
           // q에 현재의 날짜와 익은 감자의 위치를 저장
           if(num == 1) q.push(make_pair(0,make_pair(i,j))) ;
           if(num==0) zeroCnt++;
       }
   }
   dp(zeroCnt);
   cout<<answer;
   return 0;
}

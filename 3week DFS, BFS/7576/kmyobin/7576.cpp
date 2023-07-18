#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int N, M, V;
int A[1001][1001];
bool visited_bfs[1001][1001];
queue<pair<int,int>> T;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// 오른쪽, 아래, 왼쪽, 위
int answer = -1;



// 하루가 지나면 익은 것들 인접한 곳의 익지 않는 것들이 익는다
// 혼자 저절로 익지 못함
// 모든 도마도가 며칠이 지나면 다 익는지?
// 1 : 익토, 0 : 낫익토, -1 : 낫토

bool safe(int y, int x){
  return (0 <= x && x < M) && (0 <= y && y < N);
}

int check(){
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      if(A[i][j]==0)
        return -1; // 안익은 토마토 있는 경우
    }
  }
  return 0; // 모두 익은 토마토
}

void show(){
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void bfs(){
    while(!T.empty()){
      // 큐에 값이 있으면 방문해야 하는 노드가 있다는 것
      int rr = T.front().first;
      int cc = T.front().second;

      T.pop();
      //cout << "q.size() : " << q.size() << endl;

      for (int i = 0; i < 4; i++){
        //cout << rr + dy[i] << ", " << cc + dx[i] << endl;
        if(safe(rr+dy[i], cc+dx[i]) && A[rr+dy[i]][cc+dx[i]]==0){
          // 영역을 넘어가지 않고, 해당 영역이 안 익은 토마토라면
          
          //A[rr + dy[i]][cc + dx[i]] = 1;
          A[rr + dy[i]][cc + dx[i]] = A[rr][cc] + 1;
          answer = (answer > A[rr + dy[i]][cc + dx[i]]) ? answer : A[rr + dy[i]][cc + dx[i]];
          //visited_bfs[rr + dy[i]][cc + dx[i]] = true;
          T.push({rr + dy[i], cc + dx[i]});
        }
      }
      //show();
    }    



}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M >> N; // 가로, 세로

  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> A[i][j];
      if(A[i][j]==1)
        T.push({i, j});
    }
  }

  if(T.empty()){
    // 익어있는 토마토 없으면 가능성 없음
    cout << -1;
  } 
  else{
    if(check()==0){
      // 이미 모두 익어있다면 (0이 없다면)
      cout << 0;
    }
    else{
      bfs();
      int ans = check();      
      if(ans==-1){
        cout << -1;
      }
      else{
        cout << answer - 1;
      }
    }

  }
  return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int A[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void show(){
  cout << "--------\n";

  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= M; j++){
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}

bool safe(int r, int c){
  return (1 <= r && r <= N) && (1 <= c && c <= M);
}

void bfs(int r, int c){
  queue<pair<int, int>> q;
  q.push(make_pair(r, c));

  while(!q.empty()){
    int rr = q.front().first;
    int cc = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++){
      int new_rr = rr + dy[i];
      int new_cc = cc + dx[i];
      if(safe(new_rr, new_cc) && A[new_rr][new_cc]==1){
        q.push(make_pair(new_rr, new_cc));
        A[new_rr][new_cc] = A[rr][cc] + 1;
      }
      if(new_rr==N && new_cc==M){
        // NÇà M¿­¿¡ µµÂøÇÏ¸é Å»ÁÖ
        break;
      }
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 1; i <= N; i++){
    string input;
    cin >> input;
    for (int j = 1; j <= input.length(); j++){
      A[i][j] = input[j - 1] - '0'; // char -> int
    }
  }

  bfs(1, 1);

  cout << A[N][M];
}
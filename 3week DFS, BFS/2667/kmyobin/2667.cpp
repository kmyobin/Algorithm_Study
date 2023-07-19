#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
int A[26][26];
bool visited[26][26];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int ans;
vector<int> B;
// 오른쪽, 아래, 왼쪽, 위

bool safe(int x, int y){
  return (0 <= x && x < N) && (0 <= y && y <= N);
}

void show(){
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++){
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

}

void bfs(int r, int c, int cnt){
  queue<pair<int, int>> q;
  q.push({r, c});

  int area = 1;

  while(!q.empty()){
    int rr = q.front().first;
    int cc = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++){
      if(safe(rr+dy[i], cc+dx[i]) && A[rr+dy[i]][cc+dx[i]]==1 && !visited[rr+dy[i]][cc+dx[i]]){
        A[rr + dy[i]][cc + dx[i]] = cnt;
        area++;
        visited[rr + dy[i]][cc + dx[i]] = true;
        q.push({rr + dy[i], cc + dx[i]});
      }

    }
  }
  B.push_back(area);
}


void solve(){
  for (int i = 0; i < N;i++){
    for (int j = 0; j < N; j++){
      if(A[i][j]==1 && !visited[i][j]){
        // 방문하지 않았던 곳이라면
        ans++;
        visited[i][j] = true;
        bfs(i, j, ans);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    string input;
    cin >> input;
    for (int j = 0; j < N; j++){
      A[i][j] = input[j] - '0';
    }
  }
  solve();

  sort(B.begin(), B.end());
  
  cout << ans << endl;

  for(auto item : B){
    cout << item << endl;
  }
}
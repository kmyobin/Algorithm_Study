#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int N, M, V;
vector<int> A[1001];
bool visited_dfs[1001];
bool visited_bfs[1001];
int answer;


void dfs(int r){
  cout << r << " ";
  visited_dfs[r] = true; // r행 방문 완료
  for (int c = 0; c < A[r].size(); c++){
    int new_r = A[r][c];
    if(!visited_dfs[new_r]){
      // c행을 방문하지 않고 A[r][c]가 1이라면
      dfs(new_r);
    }
  }
}

void bfs(int s){
  queue<int> q;
  q.push(s);
  visited_bfs[s] = true;

  while(!q.empty()){
    // 큐에 값이 있으면 방문해야 하는 노드가 있다는 것
    int x = q.front();
    q.pop();
    cout << x << " ";

    for (int i = 0; i < A[x].size(); i++){
      int new_x = A[x][i];
      if(!visited_bfs[new_x]){
        // 방문하지 않았다면
        q.push(new_x);
        visited_bfs[new_x] = true; // 방문 처리
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> M;
  cin >> V;

  for (int i = 0; i < M; i++){
    int x, y;
    cin >> x >> y;
    A[x].push_back(y);
    A[y].push_back(x);
  }

  for (int i = 1; i <= N; i++){
    // 오름차순 정렬 (방문 가능한 정점이 여러개인 경우 번호가 작은 것을 선택해야하므로)
    sort(A[i].begin(), A[i].end());
  }

  dfs(V);
  cout << endl;
  bfs(V);

  return 0;
}
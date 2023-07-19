#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

/*
1 - 2 5
2 - 1 3 5
3 - 2
4 - 7
5 - 1 2 6
6 - 5
7 - 4
*/
int N;
int M;
vector<int> A[101];
bool visited[101];
int answer;


void dfs(int r){
  visited[r] = true; 
  //cout << "A[" << r << "].size : " << A[r].size() << endl;
  for (int c = 0; c < A[r].size(); c++){
    int new_r = A[r][c];
    if(!visited[new_r]){
      answer++;
      dfs(new_r);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  cin >> M;

  for (int i = 0; i < M; i++){
    int x, y;
    cin >> x >> y;
    A[x].push_back(y);
    A[y].push_back(x);
  }

  dfs(1);

  cout << answer;

  return 0;
}
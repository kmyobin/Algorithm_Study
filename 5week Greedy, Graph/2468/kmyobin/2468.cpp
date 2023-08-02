#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int N;
int A[101][101];
int temp[101][101];
int maximum;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// max height = 1 ~ N �� �� Ž��

bool safe(int r, int c){
  return (1 <= r && r <= N) && (1 <= c && c <= N);
}

void bfs(int r, int c, int cnt){
  queue<pair<int, int>> q;
  q.push(make_pair(r, c));
  temp[r][c] = cnt;

  while(!q.empty()){
    pair<int, int> A = q.front();
    int rr = A.first;
    int cc = A.second;
    q.pop();

    for (int i = 0; i < 4; i++){
      int new_rr = rr + dy[i];
      int new_cc = cc + dx[i];
      if(safe(new_rr,new_cc) && temp[new_rr][new_cc]==0){
        // ���� ����� ���̶��
        temp[new_rr][new_cc] = cnt;
        q.push(make_pair(new_rr, new_cc));
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int mh = -1;

  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++){
      cin >> A[i][j];
      temp[i][j] = A[i][j];
      
      mh = (mh > A[i][j]) ? mh : A[i][j];
    }
  }


  for (int k = 0; k <= mh; k++){
    // k=1���� �����ϸ� �ƹ����� ������ �ִ� Ȯ���� �����ϴ� ��
    int cnt = 0;
    for (int i = 1; i <= N; i++){
      for (int j = 1; j <= N; j++){
        if(temp[i][j]>k){
          // �� ���� ��
          temp[i][j] = 0;
        }
        else
          temp[i][j] = -1; // ���� ���̸� ����
      }
    }

    for (int i = 1; i <= N; i++){
      for (int j = 1; j <= N; j++){
        if(temp[i][j]==0){
          // ���� ������ ���̸�
          bfs(i, j, cnt + 1); // bfs ����
          cnt++;
        }
      }
    }

    //cout << "cnt : " << cnt << endl;
    maximum = maximum > cnt ? maximum : cnt;

    // temp �迭 �ٽ� A �迭�� �ʱ�ȭ
    for (int i = 1; i <= N; i++){
      for (int j = 1; j <= N;j++){
        temp[i][j] = A[i][j];
      }
    }
  }

  cout << maximum;
}
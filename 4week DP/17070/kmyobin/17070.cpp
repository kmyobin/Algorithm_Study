#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int N;
int A[17][17];
int dp[17][17][4];

/*
dp[i][j][1] = i행 j열에서 가로 방향으로 들어오는 방법의 개수
dp[i][j][2] = i행 j열에서 세로 방향으로 들어오는 방법의 개수
dp[i][j][3] = i행 j열에서 대각선 방향으로 들어오는 방법의 개수
*/


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 1; i <= N;i++){
    for (int j = 1; j <= N; j++){
      cin >> A[i][j];
    }
  }

  dp[1][2][1] = 1; // 맨 처음에 가로로 놓여있으므로

  for (int i = 1; i <= N; i++){
    for (int j = 3; j <= N; j++){
      if(A[i][j]==1) // 벽이면 건너뜀
        continue;
      // 1. i행 j열에 가로로 들어오는 경우 : 가로로 들어오거나 대각선으로 들어오는 것 (i, j-1에 벽이 없거나, i-1, j-1에 벽이 없음)
      if(A[i][j-1]==0 || A[i-1][j-1]==0)  dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][3];
      // 2. i행 j열에 세로로 들어오는 경우 : 세로로 들어오거나 대각선으로 들어오는 것 (i-1, j에 벽이 없거나, i-1, j-1에 벽이 없음)
      if(A[i-1][j]==0 || A[i-1][j-1]==0)  dp[i][j][2] = dp[i - 1][j][2] + dp[i - 1][j][3];
      // 3. i행 j열에 대각선으로 들어오는 경우 : 위쪽, 왼쪽, 왼쪽 대각선에 모두 벽이 없어야함
      if(A[i][j-1]==0 && A[i-1][j]==0 && A[i-1][j-1]==0)  dp[i][j][3] = dp[i-1][j - 1][1] + dp[i - 1][j-1][2] + dp[i - 1][j - 1][3];
    }
  }

  cout << dp[N][N][1] + dp[N][N][2] + dp[N][N][3];

  return 0;
}
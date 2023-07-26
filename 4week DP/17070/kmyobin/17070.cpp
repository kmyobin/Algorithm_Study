#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int N;
int A[17][17];
int dp[17][17][4];

/*
dp[i][j][1] = i�� j������ ���� �������� ������ ����� ����
dp[i][j][2] = i�� j������ ���� �������� ������ ����� ����
dp[i][j][3] = i�� j������ �밢�� �������� ������ ����� ����
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

  dp[1][2][1] = 1; // �� ó���� ���η� ���������Ƿ�

  for (int i = 1; i <= N; i++){
    for (int j = 3; j <= N; j++){
      if(A[i][j]==1) // ���̸� �ǳʶ�
        continue;
      // 1. i�� j���� ���η� ������ ��� : ���η� �����ų� �밢������ ������ �� (i, j-1�� ���� ���ų�, i-1, j-1�� ���� ����)
      if(A[i][j-1]==0 || A[i-1][j-1]==0)  dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][3];
      // 2. i�� j���� ���η� ������ ��� : ���η� �����ų� �밢������ ������ �� (i-1, j�� ���� ���ų�, i-1, j-1�� ���� ����)
      if(A[i-1][j]==0 || A[i-1][j-1]==0)  dp[i][j][2] = dp[i - 1][j][2] + dp[i - 1][j][3];
      // 3. i�� j���� �밢������ ������ ��� : ����, ����, ���� �밢���� ��� ���� �������
      if(A[i][j-1]==0 && A[i-1][j]==0 && A[i-1][j-1]==0)  dp[i][j][3] = dp[i-1][j - 1][1] + dp[i - 1][j-1][2] + dp[i - 1][j - 1][3];
    }
  }

  cout << dp[N][N][1] + dp[N][N][2] + dp[N][N][3];

  return 0;
}
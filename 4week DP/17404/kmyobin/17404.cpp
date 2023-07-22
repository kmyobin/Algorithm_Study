#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int N;
int A[1001][4];
int dp[1001][4];
int minimum = INT_MAX;

void show(){
  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
      cout << dp[i][j] << " ";
    }  
    cout << endl;
  }

}

void DP(int rgb){
  int first = rgb;
  // dp 1행 설정
  for (int j = 1; j <= 3; j++){
    if(j==first){ // 첫번째 RGB값에 해당하는 j라면
      dp[1][j] = A[1][j];
    }
    else{
      dp[1][j] = 1000000000; // INT_MAX로 설정하면 overflow 발생
    }
  }
  for (int i = 2; i <= N; i++)
  {
    dp[i][1] = min(dp[i - 1][2] + A[i][1], dp[i - 1][3] + A[i][1]);
    dp[i][2] = min(dp[i - 1][1] + A[i][2], dp[i - 1][3] + A[i][2]);
    dp[i][3] = min(dp[i - 1][1] + A[i][3], dp[i - 1][2] + A[i][3]);
  }

  for (int j = 1; j <= 3; j++){
    if(first==j){
      // 첫 집과 마지막 집의 색이 같다면
      continue;
    }
    minimum = min(minimum, dp[N][j]);
  }
  //show();
  //cout << "-------\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= 3; j++){
      cin >> A[i][j];
    }
  }

  DP(1);
  DP(2);
  DP(3);

  cout << minimum;

  return 0;
}
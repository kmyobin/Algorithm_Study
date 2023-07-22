#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int N;
int ans;
int A[1001];
int dp[1001];
/*
10
1 2 0 1 3 2 1 5 4 2

dp[1]=0, dp[2]=1
dp[2]=1, dp[3]=2, dp[4]=2
dp[3]=2
dp[4]=2, dp[5]=3
dp[5]=3, dp[6]=4, dp[7]=4, dp[8]=4
dp[6]=4, dp[7]=4 vs 5, dp[8]=4 vs 5 (기존 dp[i] vs dp[i]+1)
dp[7]=4

dp[i]=i번째 칸에서 최소 점프 횟수
*/


void show(){
  for (int i = 1; i <= N; i++)
  {
    cout << dp[i] << " ";
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++){
    cin >> A[i];
  }

  for (int i = 1; i <= N; i++){
    dp[i] = min(dp[i - 1] + 1, dp[i]); // 그전에서 +1, 기존 횟수를 비교해서 작은 값을 넣음
    int jump = A[i];
    for (int j = i + 1; j <= i + jump; j++){
      // 점프할 수 있는 모든 인덱스 탐색
      if(dp[j]==0){
        // 아직 아무 값도 들어가 있지 않은 상황이라면
        dp[j] = dp[i] + 1; // 기존 횟수 + 1
      }
      else{
        // 이미 값이 들어가있는 상황이면
        dp[j] = min(dp[j], dp[i] + 1); 
      }
    }
  }

  bool err = false;
  for (int i = 2; i <= N; i++){
    if(dp[i]==0){ // dp 중간에 0이 있으면 끊긴 것이므로 끝까지 못감
      cout << -1;
      err = true;
      break;
    }
  }
  if(!err)  cout << dp[N];

  return 0;
}
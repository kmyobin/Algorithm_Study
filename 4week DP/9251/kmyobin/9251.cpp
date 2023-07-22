#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string A, B;
int dp[1001][1001];
// LCS 문제 : 최장 공통 부분 수열


void show(int a_len, int b_len){
  for (int i = 1; i <= a_len; i++){
    for (int j = 1; j <= b_len; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;
  for (int i = 1; i <= A.length(); i++)
  {
    for (int j = 1; j <= B.length(); j++)
    {
      if(A[i-1]==B[j-1]){
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else{
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
  }
  }
  
  cout << dp[A.length()][B.length()];

  return 0;
}
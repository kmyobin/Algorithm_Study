#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> A;
int ans;
bool cmp(int a, int b){
  return a > b; // 내림차순
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int input;
    cin >> input;
    A.push_back(input);
  }

  sort(A.begin(), A.end(), cmp); // greater<int>()

  for (int i = 0; i < N; i++){
    int big = A[i];
    int small = 0;
    if(i+2<N)
      small = A[i + 1] + A[i + 2];
    if(small>big){
      cout << big + small;
      return 0;
    }
  }

  cout << -1;
}
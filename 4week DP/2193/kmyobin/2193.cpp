#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int N;
int ans;
long long int A[91] = {
    0,
    1,
    1,
};

/*
  3
  1 0 0
  1 0 1

  A[1]=1 A[2]=1 A[3]=2 A[4]=3 A[4]=5

  4
  1 0 0 0
  1 0 0 1
  1 0 1 0

  5
  1 0 0 0 0
  1 0 0 0 1
  1 0 0 1 0
  1 0 1 0 0
  1 0 1 0 1

*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  
  for (int i = 3; i <= N; i++){
    A[i] = A[i - 1] + A[i - 2];
  }

  cout << A[N];

  return 0;
}
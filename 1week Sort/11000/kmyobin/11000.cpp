#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> PQ; // 오름차순 정렬
vector<pair<int, int>> A;

void quicksort(int left, int right){
  if(left>=right)
    return;

  int p_right = right;
  int p_left = left;

  int pivot = A[(left + right) / 2].first;

  while(p_left<=p_right){
    // 시작 시간(s) 기준으로 오름차수 정렬
    while(A[p_left].first<pivot){
      p_left++;
    }
    while(pivot<A[p_right].first){
      p_right--;
    }
    if(p_left<=p_right){
      swap(A[p_left], A[p_right]);
      p_left++;
      p_right--;
    }
  }

  quicksort(left, p_right);
  quicksort(p_left, right);
}


int N;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N;i++){
    int s, t;
    cin >> s >> t;
    A.push_back(make_pair(s, t));
  }

  // 시작 기준으로 오름차순 정렬 (s)
  quicksort(0, N - 1);

  // 우선순위 큐에 끝나는 시간(t) push
  PQ.push(A[0].second); // 오름차순
  
  // 첫번째 인덱스부터 접근
  for (int i = 1; i < N; i++){
    if(A[i].first<PQ.top()){
      // 안끝났으면 강의실 추가 == i번째 인덱스의 끝나는 시간 추가
      PQ.push(A[i].second);
    }
    else{
      // 끝났으면 강의실 이어서 쓸 수 있음 == PQ pop, i번째 인덱스의 끝나는 시간 추가(새로운 수업이 생겼으므로)
      PQ.pop();
      PQ.push(A[i].second);
    }
  }

  cout << PQ.size();

  return 0;
}
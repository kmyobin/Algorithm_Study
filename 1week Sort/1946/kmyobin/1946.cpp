#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*
  모든 지원자와 비교했을 때, 서류심사, 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발
  ex) A 성적이 B 성적보다 둘 다 낮으면 탈락
*/

vector<pair<int, int>> A;

void quicksort(int left, int right){
  if(left>=right)
    return;

  int p_right = right;
  int p_left = left;

  int pivot = A[(left + right) / 2].first;

  while(p_left<=p_right){
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

void show(int N){
  for (int i = 0; i < N; i++)
  {
    cout << A[i].first << ", " << A[i].second << endl;
  }
  
}

int compare_interview(int N){
  int cnt = N;
  int low_grade = A[0].second;
  int high_grade = A[0].second;
  for (int i = 1; i < N; i++)
  {
    if(A[i].second>low_grade){
      // 제일 낮은 애보다 낮은 순위라면
      cnt--;    
    }
    else{
      low_grade = A[i].second;
    }
  }

  return cnt;
}

int T, N;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  
  for (int i = 0; i < T; i++)
  {
    cin >> N;
    A.clear();
    for (int j = 0; j < N; j++)
    {
      int a, b;
      cin >> a >> b;
      A.push_back(make_pair(a, b));      
    }

    quicksort(0, N - 1); // 정렬

    // 서류 기준으로 오름차순 정렬 완료

    cout << compare_interview(N) << endl;
  }
  
  
}
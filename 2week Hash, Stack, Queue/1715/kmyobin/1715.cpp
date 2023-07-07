#include <iostream>
#include <queue>
using namespace std;


// 우선순위 큐 : 우선순위가 높은 데이터가 먼저 나가는 형태의 자료구조
priority_queue<int, vector<int>, greater<int>> pq; // 오름차순
int N;
int A[100001];
int score;
int k;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int input;
    cin >> input;
    pq.push(input); // 오름차순 정렬
  }

  if(pq.size()==1){
    cout << 0;
  }
  else{
    while(!pq.empty()){
      int answer = pq.top();
      pq.pop();
      answer += pq.top();
      pq.pop();

      A[k] = answer;
      if(pq.empty()){
        k++;
        break;
      }
      pq.push(answer);
      k++;
    }
    for (int j = 0; j < k; j++){
      score += A[j];
    }
    cout << score;
  }

  return 0;
}
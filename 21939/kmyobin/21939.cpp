#include <iostream>
#include <set>
#include <string>
using namespace std;

multiset<pair<int, int>> MM;
int A[100001];
int N, M;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int P, L;
    cin >> P >> L; // 문제 번호, 난이도 순
    MM.insert(make_pair(L, P));
    A[P] = L; // A[문제 번호]에 난이도 넣기
  }
  cin >> M;
  for (int i = 0; i < M; i++)
  {
    string input;
    cin >> input;

    if(input=="recommend"){
      int x;
      cin >> x;
      if(x==1){
        // 어려운것
        cout << prev(MM.end())->second << endl;
      }
      else{
        // 쉬운 것
        cout << MM.begin()->second << endl;
      }
    }

    else if(input=="add"){
      int p, l;
      cin >> p >> l;
      
      MM.insert(make_pair(l,p));
      A[p] = l;
    }

    else{
      // 제거
      int p;
      cin >> p;
      auto it = MM.find(make_pair(A[p], p)); // 해당 난이도, 문제 번호 찾기

      MM.erase(it);
    }
  }
  
}
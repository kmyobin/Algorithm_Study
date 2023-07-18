#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int L, C;
vector<string> A;
vector<string> ans;
bool visited[16];

// 최소 한 개의 모음(a,e,i,o,u)와 최소 두 개의 자음
// 알파벳 정렬해야 함
// a c i s t w
// 정렬했으므로 조합


void print(){
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i];
  }
  cout << endl;
}
void backtracking(int cnt, int index, int mo, int ja){
  if(cnt==L){
    // 다 썼으면
    if(mo>=1 && ja>=2)  {
      print();
    }
    return;
  }

  for (int i = index; i < C; i++){
    if(visited[i]) // 방문했다면 pass
      continue;
    visited[i] = true;
    ans.push_back(A[i]);
    
    // 반복문 돌기 때문에 mo += ~ 이런거 안됨
    int new_mo = mo + (A[i] == "a" || A[i] == "e" || A[i] == "i" || A[i] == "o" || A[i] == "u"); // 모음
    int new_ja = ja + (A[i] != "a" && A[i] != "e" && A[i] != "i" && A[i] != "o" && A[i] != "u"); // 자음
    backtracking(cnt+1, i + 1, new_mo, new_ja);
    ans.pop_back();
    visited[i] = false;
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> L >> C;
  for (int i = 0; i < C; i++){
    string input;
    cin >> input;
    A.push_back(input);
  }

  sort(A.begin(), A.end());

  backtracking(0, 0, 0, 0);

  return 0;
}
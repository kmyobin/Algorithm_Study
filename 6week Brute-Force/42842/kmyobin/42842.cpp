#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    int horizontal = 0;
    int vertical = 3; // 1, 2는 세로로 적용X(노란색이 항상 중앙에 껴있어야하므로)
    while(1){
      if(total % vertical==0){ 
        // 나누어 떨어지면
        horizontal = total / vertical; // 세로 기준으로 한 이유는 가로가 더 커야하므로
        if(horizontal*2+(vertical-2)*2 == brown){
          answer.push_back(horizontal);
          answer.push_back(vertical);
          break;
        }
      }

      vertical++;
    }

    return answer;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int brown = 24;
  int yellow = 24;
  

  vector<int> ans = solution(brown,yellow);

  for (int i = 0; i < ans.size(); i++){
      cout << ans[i] << endl;
  }

      return 0;
}
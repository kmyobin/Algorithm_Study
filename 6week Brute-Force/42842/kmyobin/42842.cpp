#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    int horizontal = 0;
    int vertical = 3; // 1, 2�� ���η� ����X(������� �׻� �߾ӿ� ���־���ϹǷ�)
    while(1){
      if(total % vertical==0){ 
        // ������ ��������
        horizontal = total / vertical; // ���� �������� �� ������ ���ΰ� �� Ŀ���ϹǷ�
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
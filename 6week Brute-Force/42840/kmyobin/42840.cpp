#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct A{
  int num;
  int total = 0;
};

bool cmp(struct A a, struct A b){
  return a.total > b.total;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    struct A aa[3];
    for (int i = 0; i < 3; i++){
      aa[i].num = i + 1;
    }

    int len = answers.size();
    for (int i = 0; i < len; i++){
      if(answers[i]==one[i%5]){
        aa[0].total++;
      }
      if(answers[i]==two[i%8]){
        aa[1].total++;
      }
      if(answers[i]==three[i%10]){
        aa[2].total++;
      }
    }

    sort(aa, aa + 3, cmp);

    int maximum = aa[0].total;
    answer.push_back(aa[0].num); // 최댓값 먼저 담고

    bool isDup = false;
    for (int i = 1; i < 3; i++){
      if(aa[i].total==maximum){
        // 높은 점수를 받은 사람이 여럿일 경우
        answer.push_back(aa[i].num); // 수포자[i] 담기
        isDup = true;
      }
    }

    if(isDup){
      sort(answer.begin(), answer.end()); // 오름차순 정렬
    }

    return answer;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> input;
  input.push_back(1);
  input.push_back(3);
  input.push_back(2);
  input.push_back(4);
  input.push_back(2);

  vector<int> ans = solution(input);

  for (int i = 0; i < ans.size(); i++){
      cout << ans[i] << endl;
  }

  return 0;
}
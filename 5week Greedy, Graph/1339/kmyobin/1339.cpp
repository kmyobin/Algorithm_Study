#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
string A[11];

struct alphabet{
  char alpha;
  int weight;
};
struct alphabet alphabet[26];

bool cmp(struct alphabet a, struct alphabet b){
  return a.weight > b.weight; // 가중치 기준 정렬
}

bool cmp2(struct alphabet a, struct alphabet b){
  return a.alpha < b.alpha; // 알파벳순 정렬
}

void show(){
  for (int i = 0; i < N; i++){
    cout << A[i] << endl;
  }
}

void init(){
  for (int i = 0; i < 26; i++){
    alphabet[i].alpha = i + 'A'; // 알파벳 설정
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init(); // alphabet 배열 초기화

  cin >> N;
  int maxi = -1;
  for (int i = 0; i < N; i++){
    cin >> A[i];
    int len = A[i].length();
    maxi = (len > maxi) ? len : maxi; // 최대 자릿수 설정
  }

  // '0' 채워넣기
  for (int i = 0; i < N; i++)
  {
    int num = maxi - A[i].length(); // 남는 자릿수
    if(num==0)
      continue;
    string temp = "";
    for (int j = 0; j < num; j++){
      temp.push_back('0');
    }

    A[i].insert(0, temp); // 남는 자릿수만큼 '0' 추가
  }

  // 가중치 부여하기 
  // 행 먼저 탐색
  for (int i = 0; i < maxi; i++){ // 열
    for (int j = 0; j < N; j++){ // 행
      if(A[j][i]!='0'){ // 방금 채워넣은 '0'이 아니라면
        int alph_idx = A[j][i] - 65; // 인덱스 저장
        alphabet[alph_idx].weight += pow(10, maxi - (i + 1)); // 가중치 부여
      }
    }
  }

  sort(alphabet, alphabet + 26, cmp); // 가중치순(내림차순) 정렬

  // 가중치 숫자(0~9)로 바꾸기
  int num = 9; // 9부터 시작하여 점점 감소하는 숫자
  for (int i = 0; i < 26; i++){
    if(alphabet[i].weight==0) // 가중치가 0이면 그 뒤는 이미 0으로 탈주
      break;
    alphabet[i].weight = num; // 가중치를 숫자로 바꿈
    num--;
  }

  sort(alphabet, alphabet + 26, cmp2); // 다시 알파벳순(오름차순) 정렬
  
  int ans = 0;
  for (int i = 0; i < N; i++){ // 행
    string temp = "";
    for (int j = 0; j < maxi; j++){ // 열
      if(A[i][j]!='0')
      { // 채워넣었던 '0'이 아니라면
        int num = alphabet[A[i][j] - 65].weight; // 숫자
        temp.push_back(num + '0'); // int -> char
      }
    }
    ans += stoi(temp); // string -> int
  }
  cout << ans;
}
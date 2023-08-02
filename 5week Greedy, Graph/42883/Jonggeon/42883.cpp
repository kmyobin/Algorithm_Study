//30분이내
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
   string answer = "";
   int start = 0;
   //만들어야하는 문자열의 길이
   k = number.length()-k;
   while(k!=0){
       char temp = '0';
       int startTemp=start;
       // 시작과 끝을 정한다
       // 만들어야하는 문자열의 길이만큼 뒤에서 시작
       // 시작은 이미 정답에 넣은 인덱스 다음값
       // 같은 값이면 최대한 앞에서 시작
       for(int i = number.length()-k; i>=start; i--){
           if(number[i] >= temp){
               startTemp = i;
               temp = number[i];
           }
       }
       start = startTemp + 1;
       answer+=temp;
       k--;
   }
   return answer;
}
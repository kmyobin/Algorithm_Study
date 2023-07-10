#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
   int answer = 0;
   // 같은 카테고리에 들어갈 옷들을 관리하기 위한 multimap
   //같은 카테고리(key)에 여러개의 옷을 넣어야 하기 때문에 중복을 허용하는 multimap 사용
   multimap<string,string> m;
   // 카테고리를 관리하기 위한 set, 같은 이름의 카테고리가 여러개일 필요가 없기 때문에 set사용
   set<string> s;

   // 카테고리 별로 m에 옷들을 담고
   // 케테고리를 set에 담는다.
   for(vector<string> strs: clothes){
       m.insert(make_pair(strs[1], strs[0]));
       s.insert(strs[1]);
   }
    //카테고리가 여러개 라면
   if(s.size() != 1){
       set<string>::iterator iter=s.begin();
       answer = 1;
        // 카테고리 별로 몇개의 옷이 있는지 확인하여 곱한다
       for(iter;iter!=s.end();iter++){
           answer *= (m.count(*iter) + 1);
       }
       answer -= 1;
   }
    // 카테고리가 1개만 있다면 
   else{
        //해당 카테고리의 옷 수만 출력
       set<string>::iterator iter=s.begin();
       answer = m.count(*iter);
   }
   return answer;
}
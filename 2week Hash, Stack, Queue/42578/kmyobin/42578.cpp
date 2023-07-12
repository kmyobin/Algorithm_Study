#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    multimap<string, string> um; // key : string (옷 종류), value : string (옷 이름)
    string x[30]; // 옷의 종류를 담는 배열
    int k = 0; // 옷의 종류를 담을 x 배열의 index

    for (int i = 0; i < clothes.size(); i++)
    {
      um.insert(make_pair(clothes[i].back(), clothes[i].front()));

      bool isIter = false;
      for (int j = 0; j < k; j++){
        if(x[j]==clothes[i].back()){
          isIter = true;
          break;
        }
      }

      if(!isIter){
        x[k] = clothes[i].back();
        k++;
      }
    }

    answer = 1; // 곱하는 것이므로 1로 설정

    for (int i = 0; i < k; i++){
      answer *= (um.count(x[i]) + 1);
    }

    answer--; // 아무것도 안입으면 안되므로

    return answer;
}

int main(){
    vector<vector<string>> clothes;
    //clothes.push_back({"yellow_hat", "headgear"});
    //clothes.push_back({"blue_sunglasses", "eyewear"});
    //clothes.push_back( {"green_turban", "headgear"} );

    clothes.push_back({"crow_mask", "face"});
    clothes.push_back({"blue_sunglasses", "face"});
    clothes.push_back( {"smoky_makeup", "face"} );
    cout << solution(clothes) << endl;

    return 0;
}
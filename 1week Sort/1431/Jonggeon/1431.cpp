#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    //튜플 사용
    vector<tuple<int,int,string>> v;
    for(int i = 0; i < n ; i++){
        string str;
        cin >> str;
        int length = str.length();
        int sum = 0;
        for(int j=0; j<length; j++){
            if(str[j]-'0' >= 0 && str[j] - '0' <= 9){
                sum += (str[j] - '0');
            }
        }
        v.push_back(make_tuple(length,sum,str));
    }
    //길이, 숫자합, 문자열 순으로 정렬
    sort(v.begin(),v.end());
    for(tuple<int,int,string> answer: v){
        cout<< get<2>(answer)<<"\n";
    }
    return 0;
}


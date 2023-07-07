 /*
 과제
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//20분
int board[1001];
int main(void) {
    int n;
    cin >> n;
    int answer = 0;
    // d와 w를 담을 벡터
    vector<pair<int,int>> v;
    // 벡터 초기화
    for(int i = 0; i < n ; i++){
        int d;
        int w;
        cin >> d >> w;
        //w부터 담아서 점수로 sort할 수 있게 한다.
        v.push_back(make_pair(w,d));
    }
    //작은순으로 sort
    sort(v.begin(),v.end());
    // 점수가 작은 순이라 뒤에서 부터 시작
    for(int i = n-1; i >= 0 ; i--){
        int d = v[i].second;
        int w = v[i].first;
        // board배열에 자신의 시간을 인덱스로 하여 이미 존재하는 점수가 있는지 확인
        // 점수가 자신보다 낮다면 그 자리에 자신의 점수를 넣고 원래 있던 점수를 이전의 자리에 넣는다.
        while(1){
            if(d < 0) break;
            if(board[d] >= w) d--;
            else{
                int temp = board[d];
                board[d] = w;
                w = temp;
                if(w == 0) break;
            }
        }
    }
    // 얻을 수 있는 점수들의 합
    for(int i = 1; i < 1001; i++ ){
        answer += board[i];
    }
    cout<<answer<<"\n";
    return 0;
}
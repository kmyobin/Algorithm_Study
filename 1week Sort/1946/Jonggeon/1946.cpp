// 신입 사원
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    for(int i = 0; i < t ; i++){
        int n;
        cin >> n;
        vector<pair<int, int>> scores;
        // scores에 서류와 면접 순위를 담는다.
        for(int j = 0; j < n; j++){
            int a;
            int b;
            cin >> a >> b;
            scores.push_back(make_pair(a,b));
        }
        // scores를 순위별로 sort한다.
        sort(scores.begin(),scores.end());
        int answer = 0;
        int min = 9999999;
        // 서류순위로 sort되었기 때문에 현재의 서류점수는 이전 서류 점수보다 낮다.
        // 고로 면접순위만 비교하여 합격불합격 여부를 구분할 수 있다.
        // 이전 면접 순위 중 높은 것과 비교하여 자신이 더 높으면 합격할 수 있다.
        for(int j = 0; j < n; j++){
            if(scores[j].second < min){
                min = scores[j].second;
                answer++;
            }
        }
       cout<<answer<<"\n";
    }
    return 0;
}

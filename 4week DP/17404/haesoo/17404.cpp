#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int cost[1001][3], map[1001][3];
//R : cost[i][0] G : cost[i][1] B : cost[i][2]
int main() {
    cin >> N;
    int count = 2000000000;
    for (int i = 0; i < N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    for(int f = 0; f < 3; f++) { //1번 집 고정 색상
        for (int i = 0; i < 3; i++) {
          if (i == f) map[0][i] = cost[0][i];
          else map[0][i] = 1000000000;
        }
        for (int i = 1; i <= N - 1; i++) {//2 ~ 마지막 집까지
            map[i][0] = min(map[i - 1][1], map[i - 1][2]) + cost[i][0]; // 현재 R이면 이전 G, B 중 
            map[i][1] = min(map[i - 1][0], map[i - 1][2]) + cost[i][1];
            map[i][2] = min(map[i - 1][0], map[i - 1][1]) + cost[i][2];
        }
        for (int i = 0; i < 3; i++) {
            if (i == f) continue; // 마지막 집이랑 첫 번째 집이랑 같은 경우 skip
            count = min(count, map[N - 1][i]);
        }
    }
    cout << count;
} 
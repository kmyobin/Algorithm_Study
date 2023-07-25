#include <iostream>
using namespace std;
#define MAX 1000000000

int map[1001];
int A[1001]; // 칸 별 정수를 저장 (해당 칸에서 최대 점프 가능한 값)

int main() {
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        map[i] = MAX;
    }
    map[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= A[i]; j++) {
            if (map[i] != MAX) map[i + j] = min(map[i + j], map[i] + 1);
        }
    }
    if (map[N - 1] == MAX) cout << "-1";
    else cout << map[N - 1];
} 
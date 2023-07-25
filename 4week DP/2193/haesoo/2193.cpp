#include <iostream>
using namespace std;
#define MAX 100
long long DP[MAX];

int main() {
    int N;
    cin >> N;
    DP[1] = 1;
    for (int i = 2; i < N + 1; i++) DP[i] = DP[i - 2] + DP[i - 1]; 
    cout << DP[N];
}


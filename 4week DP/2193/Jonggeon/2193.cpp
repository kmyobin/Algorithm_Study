#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

long long board[100];
int main(void) {
    int n;
    cin >> n;
    board[1] = 1;
    board[2] = 1;
    board[3] = 2;
    for(int i = 4; i <= 90;i++){
        board[i] = board[i-1] + board[i-2];
    }
    cout<<board[n];
    return 0;
}
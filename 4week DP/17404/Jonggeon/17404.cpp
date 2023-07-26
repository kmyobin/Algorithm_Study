#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int board[1001][3];
int dp[1001][3];



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int temp;
            cin >> temp;

            board[i][j] = temp;

        }
    }

    int answer = 99999999;
    for (int k = 0; k < 3; k++) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = 9999999999;

            }
        }

        for (int i = 0; i < 3; i++) {
            if (k != i) {
                dp[1][i] = min(dp[1][i], board[0][k] + board[1][i]);

            }
        }



        for (int i = 2; i < n; i++) {
            if (i == n - 1) {
                for (int j = 0; j < 3; j++) { //i
                    for (int s = 0; s < 3; s++) {
                        if (s != j) {
                            if (j == k) {}
                            else {
                                dp[i][j] = min(dp[i][j], dp[i - 1][s] + board[i][j]);
                            }
                        }
                    }
                }

            }
            else {
                for (int j = 0; j < 3; j++) { //i
                    for (int s = 0; s < 3; s++) {
                        if (j != s) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][s] + board[i][j]);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            answer = min(answer, dp[n-1][i]);
        }
    }


    cout << answer;


}
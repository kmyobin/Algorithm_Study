#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
string a;
string b;
int big = 0;
int check[1002][1002];
int dp(int x, int y) {


   check[x + 1][y + 1] = 0;
   for (int i = x + 1; i <= a.length(); i++) {
       for (int j = y + 1; j <= b.length(); j++)
       {
           if (a[i] == b[j]) { check[i + 1][j + 1] = check[i][j] + 1; }
           else {
               check[i + 1][j + 1] = max(check[i+1][j],check[i][j+1]);

           }
       }

   }
   return check[x + 1][y + 1];


}

int main() {

   for (int i = 0; i < 1002; i++) {
       for (int j = 0; j < 1002; j++) {
           check[i][j] = 0;
       }
   }
   cin >> a >>b;

   dp(-1,-1);
   cout<<check[a.length()][b.length()];

}
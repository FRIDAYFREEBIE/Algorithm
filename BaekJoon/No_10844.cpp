#include <iostream>

using namespace std;

int n;
int DP[101][10];  // DP[i][j]는 I의 길이를 가지고 J로 끝나는 경우의 수

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  // DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j + 1]



  return 0;
}
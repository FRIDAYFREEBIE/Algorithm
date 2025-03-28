#include <iostream>

using namespace std;

int n;
int DP[1000001];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  DP[1] = 0;
  for(int i = 2; i <= n; i++){
    DP[i] = DP[i - 1] + 1;                             // 1을 빼는 연산
    if(i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);  // 3으로 나누는 연산
    if(i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);  // 2로 나누는 연산
  }

  // for(int i = 1; i <= n; i++) cout << DP[i] << " ";
  
  cout << DP[n] <<"\n";

  return 0;
}
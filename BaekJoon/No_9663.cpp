#include <iostream>

using namespace std;

bool isUsed1[40]; // 열
bool isUsed2[40]; // 좌 -> 우 대각선
bool isUsed3[40]; // 우 -> 좌 대각선
int n;

int cnt = 0;
// cur 행에 퀸을 놓는 함수
void func(int cur){
  if(cur == n){
    cnt ++;
    return;
  }

  for(int i = 0; i < n; i++){
    if(!isUsed1[i] & !isUsed2[cur + i] && !isUsed3[cur - i + n - 1]){
      isUsed1[i] = true;
      isUsed2[cur + i] = true;
      isUsed3[cur - i + n - 1] = true;

      // 다음 행
      func(cur + 1);

      isUsed1[i] = false;
      isUsed2[cur + i] = false;
      isUsed3[cur - i + n - 1] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  func(0);

  cout << cnt << "\n";

  return 0;
}
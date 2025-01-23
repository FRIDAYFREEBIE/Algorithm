#include <iostream>
#include <algorithm>

using namespace std;

// 1. 게임판을 상하좌우로 기울이기 -> 왼쪽으로 기울이는 기능 + 보드판 자체를 90도 회전하는 기능
// 2. 5번 기울이는 각각의 방향을 정하기

// 왼쪽으로 기울이는 매서드
void tilt(int dir);

// 보드판을 90도 회전하는 매서드
void rotate();

int board1[21][21]; // 원본 보드
int board2[21][21]; // 복사 보드
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> board1[i][j];

  int result = 0;
  for(int temp = 0 ; temp < 1024; temp++){
    // 보드 복사
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board2[i][j] = board1[i][j];

    int brute = temp;
    for(int i = 0; i < 5; i++){
      // 회전 방향
      int dir = brute % 4;
      brute /= 4;

      // 회전
      tilt(dir);
    }

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) result = max(result, board2[i][j]);
  }

  cout << result << "\n";

  return 0;
}

void tilt(int dir){
  while(dir--) rotate();

  for(int i = 0; i < n; i++){
    int tilted[21] = {};
    
    int index = 0;
    for(int j = 0; j < n; j++){
      if(board2[i][j] == 0) continue;

      // 배열이 비어있다면 값 삽입
      if(tilted[index] == 0) tilted[index] = board2[i][j];
      // 배열의 현재 값과 삽입하려는 값이 같다면 *2
      else if(tilted[index] == board2[i][j]) tilted[index++] *= 2;
      // 다음 위치에 갚 삽입
      else tilted[++index] = board2[i][j];
    }

    for(int j = 0; j < n; j++) board2[i][j] = tilted[j];
  }
}

void rotate(){
  int temp[21][21];

  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) temp[i][j] = board2[i][j];

  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board2[i][j] = temp [n - 1 - j][i];
}
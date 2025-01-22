#include <iostream>

using namespace std;

int n, m, k, r, c;
int note[42][42], paper[12][12];

// 노트북에 붙일 수 있는지 판단하는 매서드
bool pastable(int x, int y);
// 90도 회전시키는 매서드
void rotate();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;

  while(k--){
    cin >> r >> c;

    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> paper[i][j];

    // 4방향
    for(int rot = 0; rot < 4; rot++){
      bool isPaste = false;

      for(int x = 0; x <= n - r; x++){
        if(isPaste) break;

        for(int y = 0; y <= m - c; y++){
          if(pastable(x, y)){
            isPaste = true;
            break;
          }
        }
      }

      if(isPaste) break;
      rotate();
    }
  }

  int cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(note[i][j] == 1) cnt++;
    }
  }

  cout << cnt << "\n";

  return 0;
}

bool pastable(int x, int y){
  // 붙일 수 있는지 검사
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(note[x + i][y + j] == 1 && paper[i][j] == 1) return false;
    }
  }
  
  // 종이를 노트북에 붙임
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(paper[i][j] == 1) note[x + i][y + j] = 1;
    }
  }

  return true;
}

void rotate(){
  int temp[12][12];

  // temp[12][12]에 임시로 회전하여 저장
  for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) temp[j][r - 1 - i] = paper[i][j];

  // paper에 temp의 값을 옮김
  for(int i = 0; i < c; i++) for(int j = 0; j < r; j++) paper[i][j] = temp[i][j];

  swap(r, c);
}
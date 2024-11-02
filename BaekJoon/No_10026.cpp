#include <iostream>
#include <queue>

using namespace std;

char board[100][100]; // RGB
int normalVisit[100][100]; // 정상인 방문 0: X 1: O
int colorVisit[100][100]; // 색약 방문 0: X 1: O

// 방문 방향
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    string str;
    cin >> str;

    for(int j = 0; j < str.length(); j++){
      board[i][j] = str[j];
    }
  }
  
  int normalCnt = 0; // 갯수
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      // 방문 여부
      if(normalVisit[i][j] != 0){
        continue;
      }

      // 정상 BFS
      queue<pair<int, int>> normalQueue;
      normalQueue.push({i, j});
      normalVisit[i][j] = 1;
      normalCnt++;

      while(!normalQueue.empty()){
        pair<int, int> current = normalQueue.front();
        normalQueue.pop();

        for(int dir = 0; dir < 4; dir++){
          int x = current.first + dirX[dir];
          int y = current.second + dirY[dir];

          // 범위를 벗어났음
          if(x < 0 || x >= n || y < 0 || y >= n){
            continue;
          }

          // 같은 색이 아님
          if(board[x][y] != board[current.first][current.second]){
            continue;
          }

          // 방문을 이미 했음
          if(normalVisit[x][y] == 1){
            continue;
          }

          normalVisit[x][y] = 1;
          normalQueue.push({x, y});
        }
      }
    }
  }

  int colorCnt = 0; // 갯수
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      // 방문 여부
      if(colorVisit[i][j] != 0){
        continue;
      }

      // 색약 BFS
      queue<pair<int, int>> colorQueue;
      colorQueue.push({i, j});
      colorVisit[i][j] = 1;
      colorCnt++;

      while(!colorQueue.empty()){
        pair<int, int> current = colorQueue.front();
        colorQueue.pop();

        for(int dir = 0; dir < 4; dir++){
          int x = current.first + dirX[dir];
          int y = current.second + dirY[dir];

          // 범위를 벗어났음
          if(x < 0 || x >= n || y < 0 || y >= n){
            continue;
          }

          // 방문을 이미 했음
          if(colorVisit[x][y] == 1){
            continue;
          }

          // 색깔이 다름 (B일 때)
          if(board[x][y] == 'B' && (board[current.first][current.second] == 'G' || board[current.first][current.second] == 'R')){
            continue;
          }

          // 색깔이 다름 (R, G일 때)
          if(board[current.first][current.second] == 'B' && (board[x][y] == 'G' || board[x][y] == 'R')){
            continue;
          }

          colorVisit[x][y] = 1;
          colorQueue.push({x, y});
        }
      }
    }
  }

  cout << normalCnt << "\n" << colorCnt << "\n";

  return 0;
}
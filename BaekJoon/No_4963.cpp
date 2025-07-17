#include <iostream>
#include <queue>

using namespace std;

int map[51][51];
bool visited[51][51];
int dirX[8] = {0, 1, 0, -1, -1, -1, 1, 1};
int dirY[8] = {1, 0, -1, 0, -1, 1, -1, 1};

// 2중 반복문으로 각 칸에서 BFS
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(true){
    // 초기화
    for(int i = 0; i < 51; i++){
      for(int j = 0; j < 51; j++){
        map[i][j] = 0;
        visited[i][j] = 0;
      }
    }

    int w, h;
    cin >> w >> h;
    
    if(w == 0 && h == 0) break;
    
    // 입력
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        cin >> map[i][j];
      }
    }

    // BFS
    int cnt = 0;
    queue<pair<int, int>> q;

    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        if(map[i][j] == 0 || visited[i][j]) continue;

        visited[i][j]= true;
        q.push({i, j});
        cnt++;
        
        while(!q.empty()){
          pair<int, int> current = q.front();
          q.pop();
          
          // 상하좌우, 대각선 탐색
          for(int i = 0; i < 8; i++){
            int nextX = current.first + dirX[i];
            int nextY = current.second + dirY[i];

            // 유효성 검사
            if(nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) continue;
            if(map[nextX][nextY] == 0 || visited[nextX][nextY]) continue;

            visited[nextX][nextY] = true;
            q.push({nextX, nextY});
          }
        }
      }
    }

    cout << cnt << "\n";
  }

  return 0;
}
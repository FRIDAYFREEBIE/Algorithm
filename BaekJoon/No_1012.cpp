#include <iostream>
#include <queue>

using namespace std;

int field[50][50]; // 0: 배추 X 1: 배추 O
int visit[50][50]; // 0: 방문 X 1: 방문 O

// 방문 방향
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  for(int i = 0 ; i < t; i++){
    for (int x = 0; x < 50; x++) {
      fill(field[x], field[x] + 50, 0);
      fill(visit[x], visit[x] + 50, 0);
    }


    int m, n, k;
    cin >> m >> n >> k;

    for(int j = 0; j < k; j++){
      int a, b;
      cin >> a >> b;

      field[a][b] = 1;
    }

    int cnt = 0; // 배추 갯수
    queue<pair<int, int>> q;

    for(int x = 0; x < m; x++){
      for(int y = 0; y < n; y++){
        // 이미 방문함, 배추가 아니라면
        if(visit[x][y] == 1 || field[x][y] == 0){
          continue;
        }

        visit[x][y] = 1;
        q.push({x, y});
        cnt++;
        
        while(!q.empty()){
          pair<int, int> current = q.front();
          q.pop();

          for(int dir = 0; dir < 4; dir++){
            int nx = current.first + dirX[dir];
            int ny = current.second + dirY[dir];
            
            // 범위
            if(nx < 0 || nx >= m || ny < 0 || ny >= n){
              continue;
            }

            // 방문 한 적이 있거나 배추가 아닐 때
            if(visit[nx][ny] == 1 || field[nx][ny] == 0){
              continue;
            }

            visit[nx][ny] = 1;
            q.push({nx, ny});
          }
        }
      }
    }

    cout << cnt << "\n";
  }

  return 0;
}
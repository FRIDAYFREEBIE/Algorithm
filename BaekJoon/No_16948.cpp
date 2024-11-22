#include <iostream>
#include <queue>

using namespace std;

int n, r1, c1, r2, c2;
int board[201][201]; // 체스판
int visit[201][201]; // 방문 배열
int dist[201][201]; // 거리 배열
int dx[6] = {-2, -2, 0, 0, 2, 2}, dy[6] = {-1, 1, -2, 2, -1, 1}; // 데스 나이트 이동 방향
bool isValid;

void BFS();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> r1 >> c1 >> r2 >> c2;

  BFS();

  // 이동 가능
  if(isValid) cout << dist[r2][c2] << "\n";
  // 이동 불가
  else cout << -1 << "\n";

  return 0;
}

void BFS(){
  queue<pair<int, int>> q;
  q.push({r1, c1});
  visit[r1][c1] = true;

  while(!q.empty()){
    pair<int, int> current = q.front();
    q.pop();

    if(current.first == r2 && current.second == c2){
      isValid = true;
      return;
    }

    for(int dir = 0; dir < 6; dir++){
      int nx = current.first + dx[dir];
      int ny = current.second + dy[dir];
      
      // 범위 검사
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      // 방문 검사
      if(visit[nx][ny]) continue;

      visit[nx][ny] = true;
      dist[nx][ny] = dist[current.first][current.second] + 1;

      q.push({nx, ny});
    }
  }
}
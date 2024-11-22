#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int r, c, maxDepth;
int dx[4] = {1, -1, 0, 0}, dy[4]= {0, 0, 1, -1}; // DFS 방향
string arr[21];
map<char, bool> visit; // 방문 체크

// 1. 말의 위치 (1,1)
// 2. DFS()
// 2-1. 방문 여부 검사
// 2-2. maxDepth 갱신

void DFS(int x, int y, int depth);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c;

  for(int i = 0; i < r; i++) cin >> arr[i];

  DFS(0, 0, 1);

  cout << maxDepth << "\n";

  return 0;
}

void DFS(int x, int y, int depth){
  if(depth > maxDepth) maxDepth = depth;

  visit[arr[x][y]] = true;

  for(int dir = 0; dir < 4; dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    // 범위 검사
    if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
    // 방문 검사
    if(visit[arr[nx][ny]]) continue;

    // 재귀 DFS
    DFS(nx, ny, depth + 1);

    visit[arr[nx][ny]] = false;
  }
}
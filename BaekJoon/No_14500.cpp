#include <iostream>
#include <algorithm>
using namespace std;

int arr[505][505], n, m, maxSum;
bool visit[505][505];

// DFS 방향
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// T 제외 DFS
void DFS(int x, int y, int depth, int sum){
  if(depth == 4){
    maxSum = max(maxSum, sum);
    return;
  }

  for(int dir = 0; dir < 4; dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if(visit[nx][ny]) continue;

    visit[nx][ny] = true;
    DFS(nx, ny, depth + 1, sum + arr[nx][ny]); // 재귀 DFS
    visit[nx][ny] = false;
  }
}

// T
void TShape(int x, int y){
  // 0
  if(x + 1 < n && y + 2 < m) maxSum = max(maxSum, arr[x][y] + arr[x][y + 1] + arr[x + 1][y + 1] + arr[x][y + 2]);
  // 90
  if(x + 2 < n && y + 1 < m) maxSum = max(maxSum, arr[x][y] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 2][y]);
  // 180
  if(x - 1 > -1 && y + 2 < m) maxSum = max(maxSum, arr[x][y] + arr[x][y + 1] + arr[x - 1][y + 1] + arr[x][y + 2]);
  // 270
  if(x + 2 < n && y - 1 > -1) maxSum = max(maxSum, arr[x][y] + arr[x + 1][y] + arr[x + 1][y - 1] + arr[x + 2][y]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      visit[i][j] = true;
      DFS(i, j, 1, arr[i][j]);
      visit[i][j] = false;
      TShape(i, j);
    }
  }

  cout << maxSum << "\n";

  return 0;
}
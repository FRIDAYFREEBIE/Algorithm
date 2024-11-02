#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int house[25][25]; // 1: 집
int visit[25][25]; // 0: X, 1: O

// 방문 방향
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char ch;
      cin >> ch;
      house[i][j] = ch - '0';
    }
  }

  int houseCnt = 0;
  vector<int> houseSize;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      // 집. 방문 여부
      if(house[i][j] != 1 || visit[i][j] != 0){
        continue;
      }

      queue<pair<int, int>> q;
      q.push({i, j});
      visit[i][j] = 1;
      houseCnt++;

      int size = 0;
      while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        size++;

        for(int dir = 0; dir < 4; dir++){
          int x = current.first + dirX[dir];
          int y = current.second + dirY[dir];

          // 범위
          if (x < 0 || x >= n || y < 0 || y >= n) {
            continue;
          }

          // 집, 방문 여부
          if(house[x][y] != 1 || visit[x][y] != 0){
            continue;
          }

          visit[x][y] = 1;
          q.push({x, y});
        }
      }

      houseSize.push_back(size);
    }
  }

  sort(houseSize.begin(), houseSize.end());

  cout << houseCnt << "\n";
  for(auto & v : houseSize){
    cout << v << "\n";
  }

  return 0;
}
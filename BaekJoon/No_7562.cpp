#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int visit[301][301]; // 0: X

// 방문 방향
int dirX[] = {1,2,2,1,-1,-2,-2,-1};
int dirY[] = {2,1,-1,-2,-2,-1,1,2};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  for(int i = 0; i < t; i++){
    int size;
    cin >> size;

    // 초기화
    for(int j = 0; j < size + 1; j++){
      fill(visit[j], visit[j] + size + 1, 0);
    }

    pair<int, int> knight, target;
    cin >> knight.first >> knight.second;
    cin >> target.first >> target.second;

    queue<pair<int, int>> q;
    q.push(knight);
    visit[knight.first][knight.second] = 1;

    while(visit[target.first][target.second] == 0){
      pair<int, int> current = q.front();
      q.pop();

      for(int dir = 0; dir < 8; dir++){
        int x = current.first + dirX[dir];
        int y = current.second + dirY[dir];

        // 범위
        if(x < 0 || x >= size || y < 0 || y >= size){
          continue;
        }
        
        // 방문 여부
        if(visit[x][y] != 0){
          continue;
        }

        visit[x][y] = visit[current.first][current.second] + 1;
        q.push({x, y});
      }
    }

    cout << visit[target.first][target.second] - 1 << "\n";
  }

  return 0;
}
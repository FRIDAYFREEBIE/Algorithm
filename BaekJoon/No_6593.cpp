#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char tower[30][30][30];
int visit[30][30][30];

int dirX[6] = {0, 0, 1, -1, 0, 0};
int dirY[6] = {1, -1, 0, 0, 0, 0};
int dirZ[6] = {0, 0, 0, 0, 1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while(true){
    int l, r, c;
    cin >> l >> r >> c;

    if(l == 0 && r == 0 && c == 0){
      break;
    }
    
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
          visit[i][j][k] = 0;
        }
      }
    }

    tuple<int, int, int> sangbum;
    tuple<int, int, int> escape;
    for(int i = 0; i < l; i++){
      for(int j = 0; j < r; j++){
        for(int k = 0; k < c; k++){
          cin >> tower[i][j][k];

          if(tower[i][j][k] == 'S'){
            sangbum = {i, j, k};
          }
          else if(tower[i][j][k] == 'E'){
            escape = {i, j, k};
          }
        }
      }
    }

    visit[get<0>(sangbum)][get<1>(sangbum)][get<2>(sangbum)] = 1;
    queue<tuple<int, int, int>> q;
    q.push(sangbum);

    bool isEscape = false;
    while(!q.empty() && !isEscape){
      tuple<int, int, int> current = q.front();
      q.pop();

      for(int dir = 0; dir < 6; dir++){
        int z = get<0>(current) + dirZ[dir];
        int x = get<1>(current) + dirX[dir];
        int y = get<2>(current) + dirY[dir];

        // 범위
        if(z < 0 || z >= l || x < 0 || x >= r || y < 0 || y >= c){
          continue;
        }

        // 방문, 벽
        if(visit[z][x][y] != 0 || tower[z][x][y] == '#'){
          continue;
        }
        
        // 탈출
        if(tower[z][x][y] == 'E'){
          cout <<  "Escaped in " << visit[get<0>(current)][get<1>(current)][get<2>(current)] << " minute(s)." << "\n";
          isEscape = true;
          break;
        }

        visit[z][x][y] = visit[get<0>(current)][get<1>(current)][get<2>(current)] + 1;
        q.push({z, x, y});
      }

    }
  
    if(!isEscape){
      cout << "Trapped!" << "\n";
    }
  }

  return 0;
}
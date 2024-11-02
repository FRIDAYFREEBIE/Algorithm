#include <iostream>
#include <queue>
#include <cstring> // memset

using namespace std;

int board[101];   // 1 = 사다리, -1 = 뱀
int cnt[101];     // 주사위 횟수
int ladder[101];  // a -> b
int snake[101];   // a -> b

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  memset(cnt, -1, sizeof(cnt));
  
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    board[a] = 1;
    ladder[a] = b;
  }

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    board[a] = -1;
    snake[a] = b;
  }

  queue<int> q;
  q.push(1);
  cnt[1] = 0;

  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(int dice = 6; dice > 0; dice--){
      int nPos = current + dice;

      // 범위
      if (nPos > 100) continue;

      // 방문 여부
      if (cnt[nPos] != -1) continue;

      // 사다리칸
      if(ladder[nPos] != 0){
        nPos = ladder[nPos];
      }

      // 뱀칸
      if(snake[nPos] != 0){
        nPos = snake[nPos];
      }

      // nPos가 사다리, 뱀칸에서 갱신된 경우
      if(cnt[nPos] == -1){
        cnt[nPos] = cnt[current] + 1;
        q.push(nPos);
      }

      if (nPos == 100) {
        cout << cnt[100] << "\n";
        return 0;
      }
    }
  }

  return 0;
}

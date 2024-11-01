#include <iostream>
#include <queue>

using namespace std;

int dist[100001]; // -1: 방문 X

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  fill(dist, dist + 100001, -1);

  queue<int> q;
  dist[n] = 0;
  q.push(n);

  while(dist[m] == -1){
    int current = q.front();
    q.pop();

    // +1, -1, *2
    for(int next : {current - 1, current + 1, current * 2}){
      // 범위를 벗어났다면
      if(next < 0 || next > 100001){
        continue;
      }

      // 방문 한 적이 있다면
      if(dist[next] != -1){
        continue;
      }

      dist[next] = dist[current] + 1;
      q.push(next);
    }
  }

  cout << dist[m] << "\n"; 

  return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int dist[100001]; // -1: 방문 X
int ways[100001]; // 경로

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k; 

  fill(dist, dist + 100001, -1);

  queue<int> q;
  dist[n] = 0;
  ways[n] = 1;
  q.push(n);

  while(!q.empty()){
    int current = q.front();
    q.pop();

    // -1, +1, *2
    for(int next : {current - 1, current + 1, current * 2}){
      // 범위
      if(next < 0 || next > 100000){
        continue;
      }

      // 방문 여부
      if(dist[next] == -1){
        dist[next] = dist[current] + 1;
        ways[next] = ways[current];
        q.push(next);
      }
      else if(dist[next] == dist[current] + 1){
        ways[next] += ways[current];
      }
    }
  }

  cout << dist[k] << "\n" << ways[k] << "\n";

  return 0;
}
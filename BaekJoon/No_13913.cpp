#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

// 1. BFS
// 1-1. 방문 여부, 거리 갱신(경로 탐색)
// 2. 경로 역추적

int n, k, dist[100001], temp[100001];
stack<int> way; // 경로

void BFS();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  fill(dist, dist + 100001, -1);

  // 경로가 존재하지 않음
  if(n == k) cout << 0 << "\n" << n;
  else{
    BFS();

    cout << dist[k] << "\n";

    // 경로 역추적
    int tk = k;
    while(tk != n){
      way.push(tk);
      tk = temp[tk];
    }

    way.push(n);

    while(!way.empty()){
      cout << way.top() << " ";
      way.pop();
    }

    cout << "\n";
  }

  return 0;
}

void BFS(){
  queue<int> q;
  q.push(n);
  dist[n] = 0;

  while(dist[k] == -1){
    int current = q.front();
    q.pop();

    // +1 -1 *2
    for(int next : {current + 1, current - 1, current * 2}){
      // 범위 검사
      if(next < 0 || next > 100000) continue;
      // 방문 검사
      if(dist[next] != -1) continue;

      q.push(next);
      dist[next] = dist[current] + 1;
      temp[next] = current; // 경로 저장
    }
  }
}